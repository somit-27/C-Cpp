#include<iostream>
#include<stdlib.h>
using namespace std;
int stack[10];			//initializing stack with maximum length as 10
int top=-1;				//initializing top with -1 which means it is empty
void push(int value){	//function to push an element in stack
    top++;				//incrementing top by 1 so as to store an element in it
    stack[top]=value;	//storing the value in stack with index as top
}
int pop(){				//function to pop an element from stack
    int temp;			//initializing a temporary variable for storing the element which will be popped
    temp=stack[top];	//storing the element in temp
    top--;				//decrementing the top by 1 because the element is removed and top is decreased
    return temp;		//returning the temp i.e. the value of element removed or popped
}
void display(){			//function to display the stack
    int i;				//initializing i to perform for loop for printing each element
    cout<<"The values in stack are"<<endl;
    for(i=top;i>=0;i--){
        cout<<i<<"\t"<<stack[i]<<endl;//printing the elemenets of stack in the order they are pushed or popped
    }
}
int main(){
    int ch;				//initializing ch so user can choose an operation
	while (1)		//using while to iterate as many number of times the user wants
	{
		cout<<"Choose any Operation from the following:\n";
		cout<<"1) Push\n";
		cout<<"2) Pop\n";
		cout<<"3) Display\n";
		cout<<"4) Exit\n";
		cin>>ch;
		switch (ch)		//using switch case to switch between various operations
		{
			case 1:
				int data;
				cout<<"Enter data:\n";
				cin>>data;
				push(data);
				display();
				break;
			case 2:
				int rem;
                rem=pop();
                cout<<"The element removed is: "<<rem;
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				break;
		}
        }
    return 0;
}