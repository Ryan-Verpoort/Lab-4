#include "DashLineStyle.h"

void DashLineStyle::plotLine(PointPair end_points)
{
    Count++;

    if(Count < 5) {
	auto display = getDisplay();
	display->drawLine(end_points, getColour());
    } else if(Count == 10) {
	Count = 0;
    }
}
