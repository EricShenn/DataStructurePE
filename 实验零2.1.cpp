//
//  实验零2.1.cpp
//  数据结构个人实验
//
//  Created by 沈博南 on 2017/12/13.
//  Copyright © 2017年 沈博南. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
class Point
{
private:
    double _x;
    double _y;
public:
    friend class Circle;
    Point(double x,double y)
    :_x(x),_y(y){}
    friend ostream &operator<<(ostream &out,const Point &p)
    {
        out<<"("<<p._x<<","<<p._y<<")"<<endl;
        return out;
    }
};

class Circle
{
private:
    Point center;
    double _radius;
public:
    Circle(double x=0,double y=0,double radius=0)
    :center(x,y),_radius(radius) {}
    Point &GetO()
    {
        return center;
    }
    double GetR()
    {
        return _radius;
    }
    void SetR(double radius)
    {
        _radius = radius;
    }
    void MoveTo(double x,double y)
    {
        center._x = x;
        center._y = y;
    }
    void Display()
    {
        cout<<"圆心位置："<<center;
        cout<<"圆的半径："<<_radius<<endl;
    }
    
};

int main()
{
    Circle c = Circle(1.5,2.3,10.7);
    c.Display();
    cout<<c.GetO()<<endl;
    cout<<c.GetR()<<endl;
    c.SetR(53.5);
    c.Display();
    c.MoveTo(10, 20);
    c.Display();
    
}
