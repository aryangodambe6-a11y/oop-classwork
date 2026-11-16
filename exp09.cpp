#include<iostream>
#include<string>
using namespace std;

template<class T>
class Stack{
    Tarr[10];
    int top;
    public:
    Stack(){
        top=-1;     
    }
    void push(T x)
    {
        if(top==9)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
        }
     else  
    {
        cout<<"Deleted Element: "<<arr[top--]<<endl;
    }  
}

    void display()
    {
        cout<<"Stack Elements: ";
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";  
        }
        cout<<endl;
    }
};

int main()
{
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    
    cout<<"Integer Stack:"<<endl;
    s1.display();
    s1.pop();
    s1.display();

    stack<float> s3;
    s3.push(1.5);
    s3.push(2.5);
    cout<<"Float Stack:"<<endl;
    s3.display();

    Stack<string> s2;
    s2.push("Hello");
    s2.push("World");
    cout<<"String Stack:"<<endl;
    s2.display();
    return 0;
}
