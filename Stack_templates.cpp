#include<iostream>
using namespace std;
template <class T>
class Stack{
    private:
        int top;
        T stack[100];
    public:
        Stack(){top=-1;}
        void push(T i){
            stack[++top]=i;
        }
        T pop(){
            T data=stack[top--];
            return data;
        }
        void display(){
            int i;
            for(i=0;i<=top;i++){
                cout<<stack[i]<<endl;
            }
        }
};
int main(){
    Stack<int> s1;
    Stack<string> s2;
    s1.push(10);
    s1.push(20);
    s2.push("Chup");
    s2.push("reh");
    s2.display();
    cout<<s1.pop()<<endl;
    cout<<s2.pop()<<endl;
return 0;
}