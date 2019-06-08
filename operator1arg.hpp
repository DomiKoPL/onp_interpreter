#pragma once
#include "function.hpp"

namespace calculator {

class operator1arg : public function {
public:
    virtual double get_val(double l) = 0;
    operator1arg();
    virtual ~operator1arg() = default;
};

class abs : public operator1arg {
public:
    double get_val(double l);
    abs();
};

class sgn : public operator1arg {
public:
    double get_val(double l);
    sgn();
};

class floor : public operator1arg {
public:
    double get_val(double l);
    floor();
};

class ceil : public operator1arg {
public:
    double get_val(double l);
    ceil();
};

class frac : public operator1arg {
public:
    double get_val(double l);
    frac();
};

class sin : public operator1arg {
public:
    double get_val(double l);
    sin();
};

class cos : public operator1arg {
public:
    double get_val(double l);
    cos();
};

class atan : public operator1arg {
public:
    double get_val(double l);
    atan();
};

class arccot : public operator1arg {
public:
    double get_val(double l);
    arccot();
};

class acot : public operator1arg {
public:
    double get_val(double l);
    acot();
};

class ln : public operator1arg {
public:
    double get_val(double l);
    ln();
};

class exp : public operator1arg {
public:
    double get_val(double l);
    exp();
};


} // namespace calculator 