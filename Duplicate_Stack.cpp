#include<iostream>
using namespace std;
#define size 10
int stack[size];
int nstack[size];
int top=-1,ntop=-1;
void push(int data)
{
	if (top==8){
		cout<<"Overflow";
	}
	else{
		stack[++top]=data;
	}
}
void display(){
	int i;
	for (i=0;i<=ntop;i++){
		cout<<nstack[i]<<"\t";
	}
	cout<<"\n";
}
void remdup(){
	int i,j,flag=1;
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			if (stack[i]==stack[j] && i!=j)
				flag=0;
		}
		if (flag==1){
			nstack[++ntop]=stack[i];
		}
		flag=1;
	}
}
int main(){
	int i;
	for (i=0;i<9;i++){
		cin>>stack[i];
	}
	remdup();
	display();
	return 0;
}