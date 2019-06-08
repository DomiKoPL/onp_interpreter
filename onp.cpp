#include "onp.hpp"
#include "variable.hpp"
#include "constVariable.hpp"
#include "number.hpp"
#include "operator1arg.hpp"
#include "operator2arg.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <iomanip>

using std::cout, std::cin, std::clog;
using std::string, std::vector;
using std::setw;

namespace calculator {

vector<symbol*> onp::parse_input(string const& input) {
    auto is_number = [](string & s) -> bool {
        string::size_type sz;
        try {
            std::stod(s, &sz);
        } catch (std::exception& e) {
            return false;
        }
        return sz == s.size();
    };

    std::stringstream stream(input);
    vector<symbol*> symbols;
    string sym;
    while(stream >> sym) {
        if(is_number(sym))      { symbols.push_back(new number(std::stod(sym))); } 
        else if(sym == "+")     { symbols.push_back(new plus()); }
        else if(sym == "-")     { symbols.push_back(new sub()); }
        else if(sym == "*")     { symbols.push_back(new mult()); }
        else if(sym == "/")     { symbols.push_back(new div()); }
        else if(sym == "%")     { symbols.push_back(new mod()); }
        else if(sym == "min")   { symbols.push_back(new min()); }
        else if(sym == "max")   { symbols.push_back(new max()); }
        else if(sym == "log")   { symbols.push_back(new log()); }
        else if(sym == "pow")   { symbols.push_back(new pow()); }
        else if(sym == "abs")   { symbols.push_back(new abs()); }
        else if(sym == "sgn")   { symbols.push_back(new sgn()); }
        else if(sym == "floor") { symbols.push_back(new floor()); }
        else if(sym == "ceil")  { symbols.push_back(new ceil()); }
        else if(sym == "frac")  { symbols.push_back(new frac()); }
        else if(sym == "sin")   { symbols.push_back(new sin()); }
        else if(sym == "cos")   { symbols.push_back(new cos()); }
        else if(sym == "atan")  { symbols.push_back(new atan()); }
        else if(sym == "acot")  { symbols.push_back(new acot()); }
        else if(sym == "ln")    { symbols.push_back(new ln()); }
        else if(sym == "exp")   { symbols.push_back(new exp()); }
        else if(sym == "pi")    { symbols.push_back(new constVariable("pi")); }
        else if(sym == "fi")    { symbols.push_back(new constVariable("fi")); }
        else if(sym == "e")     { symbols.push_back(new constVariable("e")); }
        else if(variable::is_variable(sym)) { symbols.push_back(new variable(sym)); }
        else { throw std::invalid_argument("Error: Invalid symbol \'" + sym + "\'."); }
    }

    return symbols;
}

double onp::calc(std::vector<symbol*> symbols) {
    std::stack<double> S;

    auto get_val = [&]() {
        if(S.empty()) {
            throw std::invalid_argument("Error: Invalid expression.");
        }
        double v = S.top(); S.pop();
        return v;
    };

    for(auto sym : symbols) {
        if(auto sy = dynamic_cast<operator2arg*>(sym); sy != nullptr) {
            double r = get_val();
            double l = get_val();
            S.push(sy->get_val(l, r));
        } else if(auto sy = dynamic_cast<operator1arg*>(sym); sy != nullptr) {
            double l = get_val();
            S.push(sy->get_val(l));
        } else if(auto sy = dynamic_cast<operand*>(sym); sy != nullptr) {
            S.push(sy->get_val());
        } else {
            throw std::invalid_argument("Error: Invalid symbol.");
        }
    }

    if(S.size() != 1u) {
        throw std::invalid_argument("Error: Invalid expression.");
    }

    return S.top();
}

onp::onp() {}

void onp::run() {
    clog << "Interacitve calculator ONP v0.1 (Jur 4 2019)\n"
            "Author: Dominik Kowalczyk\n"
            "Type \"help\" to get more information.\n";

    string input;
    while(true) {
        clog << ">> ";
        
        if(not std::getline(cin, input)) {
            clog << "\n";
            return;
        }

        if(input == "") {
            continue;
        }

        if(input == "exit" or input == "Exit") {
            return;
        }

        if(input == "help") {
            std::clog << "varlist       - show variables list\n"
                         "constlist     - show const variables list\n"
                         "clear         - delete all variables\n"
                         "print expr    - print value of expression\n"
                         "assign e to x - assign value of expression to variable x\n"
                         "exit          - exit\n";
            continue;
        }

        if(input == "varlist") {
            auto vars = variable::get_variables();
            if(vars.size() == 0u) {
                cout << "No variables assigned.\n";
            } else {
                cout << "Variables list:\n";
                cout << setw(7) << std::left << "Name" << "  Value\n";
                for(auto& [var, val] : vars) {
                    cout << setw(7) << std::left << var << "= " << val << "\n";
                }
            }
            continue;
        }

        if(input == "constlist") {
            cout << "Const Variables list:\n";
            cout << setw(4) << std::left << "Name" << "  Value\n";
            for(auto& [var, val] : constVariable::get_variables()) {
                cout << setw(4) << std::left << var << "= " << val << "\n";
            }
            continue;
        }

        if(input == "clear") {
            clog << "Are you sure you want to delete all variables?(Y/N)\n";
            string answer;
            cin >> answer;
            while(answer != "Y" and answer != "N" and answer != "Yes" and answer != "No") {
                clog << "(Y/N)\n";
                if(!(cin >> answer)) {
                    return;
                }
            }
            if(answer == "Y" or answer == "Yes") {
                variable::clear();
            }
            cin.ignore();
            continue;
        }

        auto get_command = [](string & input) {
            std::size_t p = input.find(" ");
            string res = input.substr(0, p);
            input.erase(0, p);
            return res;
        };

        string command = get_command(input);

        if(command == "print") {
            try {
                auto symbols = parse_input(input);
                cout << calc(symbols) << "\n";
                for(auto& i : symbols) {
                    delete i;
                }
            } catch(std::exception& e) {
                clog << e.what() << "\n";
            }
            continue;
        } 

        if(command == "assign") {
            auto show_correct_version = [&]() {
                clog << "Error: Syntax error.\n"
                        "You meant \'assign value to variable\'?\n";
            };

            std::size_t p = input.find(" to ");

            if(p == string::npos) {
                show_correct_version();
                continue;
            }

            string expr = input.substr(0, p);
            
            auto get_var_name = [&](string s) {
                std::stringstream st(s);
                vector<string> vars;
                while(st >> s) {
                    vars.push_back(s);
                }
                if(vars.size() != 1u) {
                    throw std::invalid_argument("Error: Variable name can't contain spaces.");
                }
                return vars[0];
            };
            
            try {
                string var = get_var_name(input.substr(p + 4));
                auto symbols = parse_input(expr);
                double val = calc(symbols);
                for(auto& i : symbols) {
                    delete i;
                }
                variable::add(var, val);
            } catch(std::exception& e) {
                clog << e.what() << '\n';
            }
            
            continue;
        }

        clog << "Error: Command \'" + command + "\' not found.\n";
    }
}

} // namespace calculator