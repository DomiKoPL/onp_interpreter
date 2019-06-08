#include "operator2arg.hpp"
#include <stdexcept>
#include <math.h>

namespace calculator {

operator2arg::operator2arg() {}

plus::plus() {}
double plus::get_val(double l, double r) { return l + r; }

sub::sub() {}
double sub::get_val(double l, double r) { return l - r; }

mult::mult() {}
double mult::get_val(double l, double r) { return l * r; }

div::div() {}
double div::get_val(double l, double r) { 
    if(r == 0.0) { throw std::logic_error("Error: Division by zero."); }
    return l / r;
}

mod::mod() {}
double mod::get_val(double l, double r) { 
    if(r == 0.0) { throw std::logic_error("Error: Division by zero."); }
    return std::fmod(l, r);
}

min::min() {}
double min::get_val(double l, double r) { return std::min(l, r); }


max::max() {}
double max::get_val(double l, double r) { return std::max(l, r); }

log::log() {}
double log::get_val(double l, double r) { 
    double a = std::log(r);
    double b = std::log(l);
    if(b == 0.0) { throw std::logic_error("Error: Division by zero."); }
    return a / b;
}

pow::pow() {}
double pow::get_val(double l, double r) { return std::pow(l, r); }

} // namespace calculator 