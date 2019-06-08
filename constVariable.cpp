#include "constVariable.hpp"

using std::string;

namespace calculator {

bool constVariable::is_const(string const& name) {
    return constVariable::const_variables.count(name);
}

constVariable::constVariable(string const& name) {
    if(not is_const(name)) {
        throw std::invalid_argument("Error: " + name + " is not a const variable.");
    }

    this->name = name;
}

double constVariable::get_val() const {
    return const_variables[name];
}

std::map<string, double> constVariable::get_variables() {
    return const_variables;
}

std::map<std::string, double> constVariable::const_variables = {
    {"pi", 3.141592653589},
    {"e", 2.718281828459},
    {"fi", 1.618033988750}
};

} // namespace calculator 