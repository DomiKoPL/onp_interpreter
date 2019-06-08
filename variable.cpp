#include "variable.hpp"
#include "constVariable.hpp"
#include <vector>
#include <algorithm>

using std::string;

namespace calculator {

bool variable::good_name(std::string const& name) {
    if(name.size() > 7u) {
        throw std::invalid_argument("Variable name too long.");
    }

    if(constVariable::is_const(name)) {
        throw std::invalid_argument("Forbidden variable name.");
    }

    static std::vector<string> forbidden_names = {
        "print", "assign", "exit", "to", "list",
        "+", "-", "*", "/", "%", "min", "max", "log", "pow", 
        "abs", "sgn", "floor", "ceil", "frac", "sin", "cos", "atan", "acot", "ln", "exp", "pi", "fi", "e"
    };

    if(std::find(forbidden_names.begin(), forbidden_names.end(), name) != forbidden_names.end()) {
        throw std::invalid_argument("\'" + name + "\' is forbidden variable name.");
    }

    if(name.size() == 0u) {
        throw std::invalid_argument("Variable name too short.");
    }

    if(std::isdigit(name[0])) {
        throw std::invalid_argument("Variable name can't start with digit.");
    }

    return true;
}

variable::variable(string const& name) {
    if(not variables.count(name)) {
        throw std::invalid_argument("Error: Variable \'" + name + "\' don't exist.");
    }
    this->name = name;
}

bool variable::is_variable(std::string const& name) {
    return variables.count(name);
}

void variable::add(string name, double val) {
    if(good_name(name)) {
        variables[name] = val;
    }
}

void variable::clear() {
    variables.clear();
}

double variable::get_val() const {
    return variables[name];
}

std::map<string, double> variable::get_variables() {
    return variables;
}

std::map<std::string, double> variable::variables;
} // namespace calculator 