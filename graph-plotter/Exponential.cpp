#include "Exponential.h"

Exponential::Exponential(float A, float b)
    : Function()
    , _A(A)
    , _b(b)
{
}

float Exponential::evaluate(float x) const
{
    return _A * exp(x * _b);
}