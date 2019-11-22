#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include <iostream>

using namespace std;

class Rectangle
{
public:
	Rectangle::Rectangle();
	Rectangle::Rectangle(int t, int b, int l, int r);//create new rectangle with given coordinates
	int Rectangle::getTop();//return top of rectangle
	int Rectangle::getBottom();//return bottom of rectangle
	int Rectangle::getLeft();//return left of rectangle
	int Rectangle::getRight();//return right of rectangle
	bool Rectangle::check_top(int bottom,int horizontal);//check rectangle whether is in top or not
	bool Rectangle::check_left(int right,int vertical);	//check rectangle whether is in left or not
private:
	int Top; // y coordinate of the upper edge
	int Left; // x coordinate of the left edge
	int Bottom; // y coordinate of the bottom edge
	int Right; // x coordinate of the right edge
};
#endif