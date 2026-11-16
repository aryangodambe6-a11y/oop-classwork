#include<iostream>
using namespace std;

class complex{
    int real,img;

    public:
    void setdata(int r,int i)   
    {
        real=r;
        img=i;
    }
    void display()
    {
        cout<<real<<" + "<<img<<"i"<<endl;
    }
    void display(string msg)
    {
        cout<<msg<<real<<" + "<<img<<"i"<<endl;
        complex operator+(comlex c)
        {
            complex temp;
            temp.real=real+c.real;
            temp.img=img+c.img;
            return temp;
    }
};

int main()
{
    complex c1,c2,c3;
    c1.setdata(3,4);
    c2.setdata(5,6);

    cout<<"First Complex Number: ";
    c1.display();
    cout<<"Second Complex Number: ";
    c2.display();

    c3=c1+c2;
    
    c3.display("Sum:");
    return 0;
}
