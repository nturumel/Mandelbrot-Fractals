//============================================================================
// Name        : Fractal.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace caveofprogramming;

int main() {

	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);
	double min = 9999999;
	double max = -9999999;
	//fractal algorithm expects to pass algorithms from -1 to 1
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			double xFractal = (x-WIDTH/2)*(2/WIDTH);
			double yFractal = (y-HEIGHT/2)*2/HEIGHT;
			if (xFractal < min)min = xFractal;
			if (xFractal >max)max = xFractal;
			bitmap.setPixel(x, y, 255, 0, 0);
		}
	}

	bitmap.write("test.bmp");

	cout << "Finished." << endl;
	return 0;
}