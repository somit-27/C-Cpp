#include<iostream>
using namespace std;
#define size 5
int a,b;
int StackA[size],StackB[size],topA=-1,topB=-1,count=0;
void push1(int value){
	if(topA >= size-1){
		cout<<"Stack is full"<<endl;
	}else{
		topA++;
		StackA[topA] = value;
	}
}
int pop1(){
	if(topA<=-1){
		cout<<"Stack is empty"<<endl;
	}else{
		return StackA[topA--];
	}
}
void push2(int value){
	if(topB >= size-1){
		cout<<"Stack is full"<<endl;
	}else{
		topB++;
		StackB[topB] = value;
	}
}
int pop2(){
	if(topB<=-1){
		cout<<"Stack is empty"<<endl;
	}else{
		return StackB[topB--];
	}
}
void enqueue(int x){
	push1(x);
	count++;
}
void dequeue(){
	int i;
	if(topA==-1 && topB==-1){
		cout<<"Queue is empty"<<endl;
	}
	else{
		for(i=0;i<count;i++){
			a = pop1();
			push2(a);
		}
		int b = pop2();
		cout<<"The dequeued element is "<<b<<endl;
		count--;
		for(i=0;i<count;i++){
			 a = pop2();
			push1(a);
		}
	}
}
void display(){
	int i;
	cout<<"The elements of queue are: "<<endl;
	for(i=0;i<=topA;i++){
		cout<<StackA[i]<<" ";
	}
}
int main(){
	enqueue(5);
	enqueue(-1);
	enqueue(2);
	dequeue();
	dequeue();
	dequeue();
	enqueue(1);
	enqueue(2);
	enqueue(3);
	display();
}