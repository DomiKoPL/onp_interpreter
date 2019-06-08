#include "operator1arg.hpp"
#include <stdexcept>
#include <math.h>

namespace calculator {

operator1arg::operator1arg() {}

abs::abs() {}
double abs::get_val(double l) { return std::abs(l); }

sgn::sgn() {}
double sgn::get_val(double l) { return (0 < l) - (l < 0); }

floor::floor() {}
double floor::get_val(double l) { return std::floor(l); }

ceil::ceil() {}
double ceil::get_val(double l) { return std::ceil(l); }

frac::frac() {}
double frac::get_val(double l) { double x; return std::modf(l, &x); }

sin::sin() {}
double sin::get_val(double l) { return std::sin(l); }

cos::cos() {}
double cos::get_val(double l) { return std::cos(l); }

atan::atan() {}
double atan::get_val(double l) { return std::atan(l); }

acot::acot() {}
double acot::get_val(double l) { return M_PI_2 - std::acos(l); }

ln::ln() {}
double ln::get_val(double l) { return std::log(l); }

exp::exp() {}
double exp::get_val(double l) { return std::exp(l); }

} // namespace calculator 