#include "rectangle.h"
#include "iostream"

using namespace std;

bool Rectangle::operator<(const Rectangle & rObj)
{
    return area < rObj.area;
}

bool Rectangle::operator<=(const Rectangle & rObj)
{
    return area <= rObj.area;
}
bool Rectangle::operator>(const Rectangle & rObj)
{
    return area > rObj.area;
}
bool Rectangle::operator>=(const Rectangle & rObj)
{
    return area >= rObj.area;
}
bool Rectangle::operator==(const Rectangle & rObj)
{
    return area == rObj.area;
}
bool Rectangle::operator!=(const Rectangle & rObj)
{
    return area != rObj.area;
}