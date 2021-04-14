#include<iostream>
#include<string.h>
using namespace std;
#define MAX 10
char stack[10];
int top=-1;
void push(char data){
    stack[++top]=data;
}
void pop(){
        top--;
}
int main(){
    int i,len;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++){
        if(s[i]=='('){
            push(s[i]);
        }
        else if(s[i]==')'){
            pop();
        }
    }
    if(top==-1){
        cout<<"expression is valid";
    }
    else{
        cout<<"expression is invalid";
    }
}