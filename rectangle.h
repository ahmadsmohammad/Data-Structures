#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "tsllist.h"


using std::ostream;

class Rectangle
{
  public:

    Rectangle(int l = 0, int w = 0)					// default constructor 
		{ length = l; width = w; area = length * width; }

    void setLength(int l)							// lengthgth mutator (setter) - updates area member
		{ length = l; area = length * width; }

    void setWidth(int w)							// width mutator (setter) - updates area member
		{ width = w; area = length * width; }

	int getLength() const							// lengthgth accessor (getter)
		{ return length; }

	int getWidth() const							// width accessor (getter)
		{ return width; }

	int getArea() const								// area accessor (getter)
		{ return area; }

	friend ostream& operator << (ostream& os, const Rectangle & rect)   // outputs a Rectangle object
	{
		os << "[L:" << rect.length << " W:" << rect.width << " (A " << rect.area << ")]";
		return os;
	}


	// implement overloads below
	bool operator<(const Rectangle &);

	bool operator<=(const Rectangle &);

	bool operator>(const Rectangle &);

	bool operator>=(const Rectangle &);

	bool operator==(const Rectangle &);

	bool operator!=(const Rectangle &);

  private:
	int length;									// length data member

	int width;									// width data member

	int area;									// area data member

};

#endif
