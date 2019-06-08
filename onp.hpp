#pragma once
#include "symbol.hpp"
#include <vector>
#include <string>

namespace calculator {

class onp {
private:
    std::vector<symbol*> parse_input(std::string const& input);
    double calc(std::vector<symbol*> symbols);
public:
    onp();
    void run();
};

} // namespace calculator 