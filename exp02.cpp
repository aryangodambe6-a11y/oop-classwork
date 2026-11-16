#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    protected:
    string brand;
};

class ElectricScooter: public Vehicle{
    private:

    int battery;

    public:

    void setDetails(string b, int batt){
        brand = b;
        battery = batt;
    }

    void showDetails(){
        cout<<"Vehicle Brand: "<<brand<<endl;
        cout<<"vehicle Battery: "<<battery<<endl;
    }
};
int main()
{
    ElectricScooter myScooter;
    myScooter.setDetails("Bajaj Chetak", 50);
    myScooter.showDetails();
    return 0;
}
