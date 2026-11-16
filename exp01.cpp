//set up a github repo. EXP 01
#include<iostream>
using namespace std;

int main()
{
    const float pi = 3.14;
    int age;
    float CircleRadius;
    string name;
    bool isStudent = true;

    cout<<"Enter your age: "<<endl;
    cin>>age;
    cout<<"Enter your name: "<<endl;
    cin>>name;
    cout<<"Enter Circle Radius: "<<endl;
    cin>>CircleRadius;
    float CircleArea = pi * CircleRadius * CircleRadius;
    int ageNextYear = age + 1;

    cout<<"\n--Results--"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
    cout<<"Circle Area: "<<CircleArea<<endl;
    cout<<"Age Next Year: "<<ageNextYear<<endl;

    if(isStudent)
    {
        cout<<"Status: Active Student"<<endl;
    }
    return 0;
}
