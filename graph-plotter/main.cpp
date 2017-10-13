#include "Graph.h"
#include "Sinusoid.h"
#include "Sampler.h"
#include "Display.h"
#include "SolidLineStyle.h"
#include "DashLineStyle.h"
#include "DotLineStyle.h"
#include "Points.h"
#include "Function.h"
#include "Exponential.h"
#include "Polynomial.h"
#include "Absolute.h"
#include <memory>

using std::shared_ptr;
using std::make_shared;

const float PI = 3.14159265359;

int main()
{
    // setup Graph with Display
    const int WIDTH = 800;
    const int HEIGHT = 600;
    shared_ptr<Display> display = make_shared<Display>(WIDTH, HEIGHT);
    Graph graph(display);

    // create sine and cosine functions
    float amplitude = 1.0;
    float frequency = 1.0;
    float phase = 0;
    Sinusoid sine_function{ amplitude, frequency, phase };
    Sinusoid cosine_function{ amplitude, frequency, phase + PI / 2 };

    // generate range and plot graphs
    Range range{ 0, 6 * PI };
    SolidLineStyle solid_red{ Colour::Red, display };
    graph.plot(generateDataPoints(sine_function, range), solid_red);

    DashLineStyle dash_red{ Colour::Red, display };
    graph.plot(generateDataPoints(sine_function, range), dash_red);

    SolidLineStyle solid_blue{ Colour::Blue, display };
    graph.plot(generateDataPoints(cosine_function, range), solid_blue);

    DotLineStyle dot_blue{ Colour::Blue, display };
    graph.plot(generateDataPoints(cosine_function, range), dot_blue);

    // Exponential e^1.5x
    Exponential exp{ 1.0, 1.5 };

    // Polynomil x^2 + 2x + 1
    vector<float> Coeffs = { 1.0, 2.0, 1.0 };
    Polynomial poly{ Coeffs };

    Range FunctionRange{ -3, 1.5 };
    graph.plot(generateDataPoints(poly, FunctionRange), solid_red);
    graph.plot(generateDataPoints(exp, FunctionRange), solid_blue);

    // Polynomial x^2 - 3x - 4
    vector<float> Coeffs_Abs = { 1.0, -3.0, -4.0 };
    shared_ptr<Polynomial> poly_Abs = make_shared<Polynomial>(Coeffs_Abs);
    Absolute Absolute_Polynomial(poly_Abs);

    Range Range_Abs{ -4, 7 };
    graph.plot(generateDataPoints(Absolute_Polynomial, Range_Abs), solid_red);

    return 0;
}

// Smooth Graphs are not produced since the sample rate is too low set to 50