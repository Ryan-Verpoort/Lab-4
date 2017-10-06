#include "DotLineStyle.h"

void DotLineStyle::plotLine(PointPair end_points)
{
    Count++;
    if(Count <= 1) {
	auto display = getDisplay();
	display->drawLine(end_points, getColour());
    } else if(Count == 2) {
	Count = 0;
    }
}
