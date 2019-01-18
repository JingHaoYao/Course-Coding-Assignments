#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "ccc_win.h"

using namespace std;

int ccc_win_main()
{
	Point cenPumpkin = cwin.get_mouse("Click to place a pumpkin");
	cwin << Circle(cenPumpkin,4) << Line(Point(cenPumpkin.get_x(),cenPumpkin.get_y() + 4), Point(cenPumpkin.get_x(),cenPumpkin.get_y() + 5)) 
		 << Point(cenPumpkin.get_x() - 1,cenPumpkin.get_y() + 1) << Point(cenPumpkin.get_x() + 1,cenPumpkin.get_y() + 1) << cenPumpkin
		 << Line(Point(cenPumpkin.get_x() - 1,cenPumpkin.get_y() - 1),Point(cenPumpkin.get_x() + 1,cenPumpkin.get_y() - 1));
}
