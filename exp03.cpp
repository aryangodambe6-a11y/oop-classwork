#include<iostream>
using namespace std;

class Student{
    private:
    string name;
    int* marks;

    public:
    student()
    {
        name="Unknown";
        marks=0;

     cout<<"Default Constructor Called"<<endl;
    }

    student(string n, int m)
    {
        name=n;
        marks=new int(m);

        cout<<"Parameterized Constructor Called"<<endl;
    }

    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<*marks<<endl;
    }
};
int main()
{
    cout<<"Default Constructor Example"<<endl;
    Student s1;
    s1.display();

    cout<<"\nParameterized Constructor Example"<<endl;
    Student s2("John", 85);
    s2.display();

    cout<<"\nCopy Constructor Example"<<endl;
    Student s3 = s2;
    s3.display();

    return 0;
}
