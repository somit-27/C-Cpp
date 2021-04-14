#include<iostream>
using namespace std;
struct data{
    int a;
    int b;
};
int main(){
    //variable
    //user defined data type Rt is name of that data that we define
    //data d1,d2,d3;
    //for address
    data *d1=new data;//dynamic storage
    data *d2=new data;
    data *d3=new data;
    cout<<"Enter the value"<<endl;
    cin>>d1->a;
    cin>>d1->b;
    cout<<"Enter the value"<<endl;
    cin>>d2->a;//also (*d2).a but change everywhere
    cin>>d2->b;
    d3->a=d1->a+d2->a;
    d3->b=d1->b+d2->b;
    cout<<d3->a<<d3->b;
}