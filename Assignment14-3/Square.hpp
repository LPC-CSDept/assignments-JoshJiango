#ifndef 	SQUARE_H
#define 	SQUARE_H

using namespace std;

class Square
{
	private:
		int width;
    
	public:
		Square();
    void setWidth(double);
    int getWidth(void) const;
    int getArea(void) const;

    friend class Rect;
};

#endif