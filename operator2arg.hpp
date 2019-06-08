#pragma once
#include "function.hpp"

namespace calculator {

class operator2arg : public function {
public:
    virtual double get_val(double l, double r) = 0;
    operator2arg();
    virtual ~operator2arg() = default;
};

class plus : public operator2arg {
public:
    double get_val(double l, double r);
    plus();
};

class sub : public operator2arg {
public:
    double get_val(double l, double r);
    sub();
};

class mult : public operator2arg {
public:
    double get_val(double l, double r);
    mult();
};

class div : public operator2arg {
public:
    double get_val(double l, double r);
    div();
};

class mod : public operator2arg {
public:
    double get_val(double l, double r);
    mod();
};

class min : public operator2arg {
public:
    double get_val(double l, double r);
    min();
};

class max : public operator2arg {
public:
    double get_val(double l, double r);
    max();
};

class log : public operator2arg {
public:
    double get_val(double l, double r);
    log();
};

class pow : public operator2arg {
public:
    double get_val(double l, double r);
    pow();
};

} // namespace calculator 