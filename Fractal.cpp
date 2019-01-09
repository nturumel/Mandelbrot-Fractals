#include<iostream>
#include"Bitmap.h"
#include "Mandelbrot.h"
#include<cstdint>

using namespace std;
using namespace caveofprogramming;
int main()
{
	int const WIDTH = 800;
	int const HEIGHT = 600;
	int const sFactor = HEIGHT;
	Bitmap bitmap(WIDTH, HEIGHT);
	/*double min1 = 999999, min2 = 999999, min3 = 999999;
	double max1 = -999999, max2 = -999999, max3 = -999999;*/
	unique_ptr<int[]>histogram(new int[Mandelbrot::MAX_ITERATIONS + 1]{});
	unique_ptr<int[]>fractal(new int[WIDTH*HEIGHT]{ 0 });
	for (int y = 0; y<HEIGHT; y++)
	{
		for (int x = 0; x<WIDTH; x++)
		{
			double xFractal = (x - WIDTH / 2-WIDTH/4)*(2.0 / sFactor);
			double yFractal = (y - HEIGHT / 2)*(2.0 / sFactor);
			
			int iterations = Mandelbrot::getIterations(xFractal, yFractal);
			if(iterations!=Mandelbrot::MAX_ITERATIONS)
				histogram[iterations]++;
			fractal[y*WIDTH + x] = iterations;
			uint8_t white = (uint8_t)(256*(double)iterations / Mandelbrot::MAX_ITERATIONS);
			bitmap.setPixel(x, y, white, white, white);
			/*if (white < min3)min3 = white;
			if (white > max3)max3 = white;
			if (xFractal < min1)min1 = xFractal;
			if (xFractal > max1)max1 = xFractal;
			if (yFractal < min2)min2 = yFractal;
			if (yFractal > max2)max2 = yFractal;*/
		}
	}
	/*int count{ 0 };
	cout << endl << endl;
	for (int i = 0;i < Mandelbrot::MAX_ITERATIONS ; i++)
	{
		cout << histogram[i] << " " << flush;
		count += histogram[i];
	}
	cout << endl << count << endl;*/
	
	/*cout << "x:" << min1 << "," << max1 << endl;
	cout << "y:" << min2 << "," << max2 << endl;
	cout <<"color:"<< min3 << "," << max3 << endl;*/
	bitmap.write("Nihar.bmp");
	cout << "Finished" << endl;
	system("pause");
	return 0;
}
