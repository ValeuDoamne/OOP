#include <iostream>
#include "Canvas.h"
#include <cmath>
/*

void Canvas::FillCircle(int x, int y, int ray, char ch);


void Canvas::FillRect(int left, int top, int right, int bottom, char ch);
*/

void Canvas::SetPoint(int x, int y, char ch)
{
	screen[y][x] = ch;
}


void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for(int x = left; x <= right; x++)
	{
		screen[top][x] = screen[bottom][x] = ch;
	}


	for(int y = top; y <= bottom; y++)
	{
		screen[y][left] = screen[y][right] = ch;
	}
}


void Canvas::DrawCircle(int xCenter, int yCenter, int ray, char ch){
	int r2, x, y;
        
        r2 = ray * ray;
        for (x = -ray; x <= ray; x++) {
            y = (int) (sqrt(r2 - x*x) + 0.5);
	    SetPoint(xCenter + x, yCenter + y, ch);
	    SetPoint(xCenter + x, yCenter - y, ch);
        }
}


void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int D = 2*dy - dx;
	int y = y1;

	for(int x = x1; x < x2; x++)
	{
		SetPoint(x, y, ch);
		if(D > 0)
		{
			y++;
			D = D - 2*dx;
		}
		D += 2*dy;
	}
}

void Canvas::Print() // shows what was printed
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
			std::cout << screen[i][j];
		std::cout << "\n";
	}
}

void Canvas::Clear() // clears the canvas
{
		
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
			SetPoint(j, i, ' ');
	}
}

