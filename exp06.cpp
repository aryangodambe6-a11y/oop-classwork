#include<iostream>
using namespace std;

class shape
{
    protected:
    int s,l,b,r,h;

    public:
    void virtual area()=0;
};

class circle: public shape
{
    public:
    void virtual area()
    {
        cout<<"Enter Radius of Circle: "<<endl;
        cin>>r;
        cout<<"Area of Circle: "<<3.14*r*r<<endl;
    }
};

class rectangle: public shape
{
    public:
    void virtual area()
    {
        cout<<"Enter Length of Rectangle: "<<endl;
        cin>>l;
        cout<<"Enter Breadth of Rectangle: "<<endl;
        cin>>b;
        cout<<"Area of Rectangle: "<<l*b<<endl;
    }
};

class triangle: public shape
{
    public:
    void virtual area()
    {
        cout<<"Enter Base of Triangle: "<<endl;
        cin>>b;
        cout<<"Enter Height of Triangle: "<<endl;
        cin>>h;
        cout<<"Area of Triangle: "<<0.5*b*h<<endl;
    }
};
int main()
{
    circle obj1;
    obj1.area();
    rectangle obj2;
    obj2.area();
    triangle obj3;
    obj3.area();    
    return 0;
}
