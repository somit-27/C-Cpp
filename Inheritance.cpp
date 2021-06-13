#include<iostream>
using namespace std;
class stu{
    protected:
        int id;
        char name[20];
    public:
        void getstu();
};
void stu :: getstu(){
    cout<<"Enter id"<<endl;
    cin>>id;
    cout<<"Enter name"<<endl;
    cin>>name;
}
class marks : public stu{
    protected:
        int mark1,mark2,mark3;
    public:
        void getmarks();
};
void marks :: getmarks(){
    cout<<"Enter all 3 marks"<<endl;
    cin>>mark1>>mark2>>mark3;
}
class sports{
    protected:
        int spmarks;
    public:
        void getsports();
};
void sports :: getsports(){
    cout<<"Enter sports marks"<<endl;
    cin>>spmarks;
}
class result : public marks, public sports{
    public:
        void show();
};
void result :: show(){
    cout<<id<<endl;
    cout<<name<<endl;
    cout<<mark1+mark2+mark3<<endl;
    int avg=(mark1+mark2+mark3)/3;
    cout<<avg<<endl;
    cout<<avg+spmarks<<endl;

}
int main(){
    result r;
    r.getstu();
    r.getmarks();
    r.getsports();
    r.show();
}