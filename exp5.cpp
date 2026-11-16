#include<iostream>
using namespace std;

class person
{
    protected:
    string name;
    int age;
    public:
    void getpersondetails()
    {
        cout<<"Enter Name: "<<endl;
        cin>>name;
       
        cout<<"Enter Age: "<<endl;
        cin>>age;
    }
    void displaypersondata()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class student : public person
    {
       protected:
       int roll_no;
       string course;
       public:
       void getstudentdetails()
       {
           getpersondetails();
           cout<<"Enter Roll No: "<<endl;
           cin>>roll_no;
           
           cout<<"Enter Course Name: "<<endl;
           cin>>course;
       }
       void displaystudentdata()
       {
           displaypersondata();
           cout<<"Roll No: "<<roll_no<<endl;
           cout<<"Course:"<<course<<endl;
       }
    };
    class graduatedstudent: public student
    {
        private:
        string specialization;
        int marks;
        public:
        void getgraduatedstudentdetails()
        {
            getstudentdetails();
            cout<<"Enter Specialization:"<<endl;
            cin>>specialization;
            cout<<"Enter Marks:"<<endl;
            cin>>marks;
        }
        
        void displaygraduatedstudentdata()
        {
            displaystudentdata();
            cout<<"Specialization: "<<specialization<<endl;
            cout<<"Marks: "<<marks<<endl;
            if(marks>=45)
            {
                cout<<"Graduated:)";
            }
            else
            {
                cout<<"Not Graduated:(";
            }
        }
    };
    int main()
    {
        graduatedstudent s1;
        
        s1.getgraduatedstudentdetails();

        cout<<"---\nDISPLAYING DETAILS---"<<endl;
        
        s1.displaygraduatedstudentdata();
        
        return 0;
    }