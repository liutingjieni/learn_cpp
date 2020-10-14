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

    Rect(const Point& leftUp, int width, int height) 
    {
       this->leftUp = leftUp;
	   this->width = width;
       this->height = height;
    }
    virtual void Draw (const Graphics& g) 
    { 
        g.DrawReactangle(Pens.red, leftUp, width, height); 
    }
};

//增加
class Circle : public Shape{
public:
	//实现自己的Draw，负责画自己
	virtual void Draw(const Graphics& g){
		g.DrawCircle(Pens.Red,
			...);
	}

};

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
    //...
	Form::OnMouseDown(e);
}

void MainForm::OnMouseUp(const MouseEventArgs& e){
	p2.x = e.X;
	p2.y = e.Y;

	if (rdoLine.Checked){
		shapeVector.push_back(new Line(p1,p2));
	}
	else if (rdoRect.Checked){
		int width = abs(p2.x - p1.x);
		int height = abs(p2.y - p1.y);
		shapeVector.push_back(new Rect(p1, width, height));
	}
	//改变
	else if (...){
		//...
		shapeVector.push_back(circle);
	}

	//...
	this->Refresh();

	Form::OnMouseUp(e);
}

void MainForm::OnPaint(const PaintEventArgs& e){

	//针对所有形状
	for (int i = 0; i < shapeVector.size(); i++){

		shapeVector[i]->Draw(e.Graphics); //多态调用，各负其责
	}

	//...
	Form::OnPaint(e);
}

