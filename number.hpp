#pragma once
#include "operand.hpp"

namespace calculator {

class number : public operand {
private:
    double val;
public:
    number(double val = 0.0);
    double get_val() const;
};

} // namespace calculator 