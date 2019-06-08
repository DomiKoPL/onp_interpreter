#pragma once

#include "operand.hpp"
#include "variable.hpp"
#include <map>
#include <string>

namespace calculator {
class constVariable : public operand {
private:
    std::string name;
    static std::map<std::string, double> const_variables;

public:
    static bool is_const(std::string const& name);
    constVariable(std::string const& name);
    double get_val() const;
    static std::map<std::string, double> get_variables();
};
} // namespace calculator 