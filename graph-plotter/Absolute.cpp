#include "Absolute.h"

Absolute::Absolute(shared_ptr<Function> PtrToFunction)
    : Function()
    , _function(PtrToFunction)
{
}

float Absolute::evaluate(float x) const
{
    return fabs(_function->evaluate(x));
}