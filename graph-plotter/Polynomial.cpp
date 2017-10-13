#include "Polynomial.h"

Polynomial::Polynomial(const vector<float> Coefficients)
    : Function()
    , _Coefficients(Coefficients)
{
}

float Polynomial::evaluate(float x) const
{
    auto polynomial = 0.f;

    for(auto i = 1; i <= _Coefficients.size(); i++) {

	polynomial += _Coefficients.at(i - 1) * pow(x, _Coefficients.size() - (i));
    }

    return polynomial;
}