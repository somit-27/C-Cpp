#include<iostream>
using namespace std;
int main(){
    int n,i;
    cin>>n;
    int stack[100],top=-1;
    do{
        top++;
        stack[top]=n%2;
        n=int(n/2);
    } while (n!=0);
    for(i=top;i>=0;i--){
        cout<<stack[i];
    }
}