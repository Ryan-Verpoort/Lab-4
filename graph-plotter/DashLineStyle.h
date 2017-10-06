#ifndef DASHLINESTYLE_H
#define DASHLINESTYLE_H

#include "LineStyle.h"

class DashLineStyle : public LineStyle
{
public:
    DashLineStyle(Colour colour, shared_ptr<Display> display_ptr)
        : LineStyle(colour, display_ptr)
    {
    }
    virtual void plotLine(PointPair end_points) override;
    int Count = 0;
};

#endif