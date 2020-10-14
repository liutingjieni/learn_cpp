/*************************************************************************
	> File Name: shape.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月13日 星期二 18时50分18秒
 ************************************************************************/

#include <vector>

class Point {
    public:
        int x;
        int y;

};
class Line {
public:
    Point start;
    Point end;

    Line(const Point& start, const Point& end)
    {
        this->start = start;
        this->end = end;
    }
};
  
//矩形
class Rect {
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
};

class From;
class MainFrom : public Form {
private:
    Point p1, p2;
    vector<Line> lineVector;
    vector<Rect> rectVector;
    
    MainFrom()
    {
        //...
    }
protected:
    virtual void onMouseDown(const MouseEventArgs& e);
    virtual void onMouseUp(const MouseEventArgs& e);
    virtual void onPoint(const MouseEventArgs& e);
};

void MainFrom::onMouseDown(const MouseEventArgs& e)
{
    p1.x = e.x;
    p1.y = e.y;

    From::onMouseDown(e);
}

void MainFrom::onMouseUp(const MouseEventArgs& e)
{
    p2.x = e.x;
    p2.y = e.y;

    if (rdoLine.checked) {
        Line line(p1, p2);
        lineVector.push_back(line);
    }
    else if (rdoRect.checked) {
        int width = abs(p2.x - p1.x);
        int height = abs(p2.y - p1.y);
        Rect rect(p1, width, height);
        rectVector.push_back(rect);
    }
    else if () {
        //...
        CircleVector.push_back(circle);
    }

    //...
    this->refresh();
    From::onMouseUp(e);
}

void MainFrom::onPoint(const PointEventArgs& e)
{
    for (int i = 0; i < lineVectror.size(); i++) {
        e.Graphics.DrawLine(Pens.red, lineVector[i].start.x, lineVector[i].start.y,
                                      lineVector[i].end.x, lineVector[i].end.y);
    }
    for (int i = 0; i < rectVectror.size(); i++) {
        e.Graphics.DrawRectangle(Pens.red, RectVector[i].leftUp, 
                                           RectVector[i].width, 
                                           RectVector[i].height);
    }
    //改变
    for (int i = 0; i < circleVectror.size(); i++) {
        e.Graphics.DrawCircle(Pens.red, circleVector[i]);
    }

    From::onPoint(e);
}

