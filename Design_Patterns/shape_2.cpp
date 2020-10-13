/*************************************************************************
	> File Name: shape_2.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月13日 星期二 19时00分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Shape {
public:
	virtual void Draw(const Graphics& g) = 0;
	virtual ~Shape() { }
};

class Point {
public:
    int x;
    int y;
};

class Line : public Shape {
public:
	Point start;
	Point end;
	
	Line(const Point& start, const Point& end) 
    {
		this->start = start;
		this->end = end;
	}

	virtual void Draw(const Graphics& g) 
    {
		g.DrawLine(Pens.Red, start.x, start.y, end.x, end.y);
	}
};

class Rect : public Shape {
public:
    Point leftUp;
    int width;
    int height;

    Rect(const Point& leftUp, int width, int height) {  }
    virtual void Draw (const Graphics& g) 
    { 
        g.DrawReactangle(Pens.red, leftUp, width, height); 
    }

}

class MainFrom : public From {
private:
	Point p1;
	Point p2;
	vector<Shape*> shapeVector;

public:
    MainFrom() {  }

protected:
    virtual void onMouseDown(const MouseEventArgs& e);
    virtual void onMouseUp(const MouseEventArgs& e);
    virtual void onPaint(const MouseEventArgs& e);

};

void MainFrom:: OnMouseUP(const MouseEventArgs& e)
{
    p2.x = e.x;
    p2.y = e.y;

}
