#pragma once

#include "symbol.hpp"

namespace calculator {

class operand : public symbol {
private:

public:
    virtual double get_val() const = 0;
};

} // namespace calculator 