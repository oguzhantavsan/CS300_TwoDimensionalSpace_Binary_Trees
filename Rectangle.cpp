#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle()
{
	Top = NULL;
	Left = NULL;
	Right = NULL;
	Bottom = NULL;
}

Rectangle::Rectangle(int t, int b, int l, int r)
{
	Top = t;
	Bottom = b;
	Left = l;
	Right = r;
}

int Rectangle::getTop()
{
	return Top;
}

int Rectangle::getBottom()
{
	return Bottom;
}

int Rectangle::getLeft()
{
	return Left;
}

int Rectangle::getRight()
{
	return Right;
}

bool Rectangle::check_top(int bottom,int horizontal)//check rectangle whether is in top or not
{
	if (bottom >= horizontal)
		return true;
	else 
	return false;

}

bool Rectangle::check_left(int right,int vertical)//check rectangle whether is in left or not
{
	if (vertical >= right)
		return true;
	else
		return false;
}

