#include<iostream>
using namespace std;
class GST{
    protected:
        double value;
    public:
    void getdata();
    virtual void display(){}
};
void GST::getdata(){
    cout<<"Enter cost of heaters";
    cin>>value;
}
class Solar_Heater : public GST{
    public:
    void display();
};
void Solar_Heater::display(){
    value=value+0.05*value;
    cout<<"Cost of Solar Heater: "<<value<<endl;
}
class Electric_Heater : public GST{
    public:
    void display();
};
void Electric_Heater::display(){
    value=value+0.12*value;
    cout<<"Cost of Electric Heater: "<<value<<endl;
}
int main(){
    GST* g;
    Solar_Heater s;
    Electric_Heater e;
    g=&s;
    g->getdata();
    g->display();
    g=&e;
    g->getdata();
    g->display();
}