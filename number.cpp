#include "number.hpp"

namespace calculator {

number::number(double val) : val(val) {}

double number::get_val() const {
    return val;
}

} // namespace calculator 