#ifndef ABSOLUTE_H
#define ABSOLUTE_H

#include "Function.h"

#include <memory>
using std::shared_ptr;

class Absolute : public Function
{

public:
    Absolute(shared_ptr<Function> _function);
    virtual float evaluate(float x) const override;

private:
    shared_ptr<Function> _function;
};

#endif