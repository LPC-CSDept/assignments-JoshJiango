#ifndef 	RECT_H
#define 	RECT_H

using namespace std;

class Square;

class Rect
{
	private:
		double width;
    double height;

	public:
		Rect();
    void setWidth(double);
    void setHeight(double);
    double getWidth(void) const;
    double getHeight(void) const;
    double getArea(void) const;
    Rect makeRectanglewithSquare(Square s);
};

#endif