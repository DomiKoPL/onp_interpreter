#pragma once
#include "operand.hpp"
#include <string>
#include <map>

namespace calculator {

class variable : public operand {
private:
    std::string name;
    static std::map<std::string, double> variables;
    static bool good_name(std::string const& name);
public:
    variable(std::string const& name);
    static bool is_variable(std::string const& name);
    static void add(std::string name, double val);
    static void clear();
    double get_val() const;
    static std::map<std::string, double> get_variables();
};

} // namespace calculator 