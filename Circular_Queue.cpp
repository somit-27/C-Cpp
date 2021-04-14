#include<iostream>
#include<stdlib.h>
using namespace std;
int front=-1,rear=-1;					//initializing front and rear as -1 which means the queue is empty
int qu[5];								//initializing a queue of max length 5
int N=5;								//storing the maximum length in a variable
int enqueue(int x){						//function for entring an element in queue
    if (front==-1 && rear==-1){			//if it is the base condition then increasing front and rear and storing the element
		front=rear=0;
		qu[rear]=x;
	}
	else if((rear+1)%N==front){			//if it follows the condition then showing that queue is full
		cout<<"Queue is full";
	}
	else{								//else increasing the rear in a way that if rear is at its last position then it shifts to first position
		rear=(rear+1)%N;
		qu[rear]=x;						//and then storing the value in rear
	}
}
void dequeue(){							//function to remove and element which if at front
    if (front==-1 && rear==-1){			//checking condition if queue is empty
		cout<<"Queue is empty";
	}
	else if(front==rear){				//if front and rear are equal it means there is only 1 element and then removing that element
		cout<<"The removed element is: "<<qu[front]<<endl;		
		front=rear=-1;					//and intializing front and end as -1 as queue is now empty
	}
	else{								//else just removing the element in its front position
		cout<<"The removed element is: "<<qu[front]<<endl;
		front=(front+1)%N;				//and then changing front in a way that if it is at its last position then it shifts to first position
	}
}
void display(){ 						//function to display
    if (front == -1){ 					//base condition to check if queue is empty
        cout<<endl<<"Queue is Empty"<<endl;
		return;  
    } 
    cout<<endl<<"Elements in Circular Queue are: "<<endl; 
    if (rear>=front) { 					//in earlier cases if rear is ahead of front then printing the elements from front to rear 
        for (int i=front;i<=rear;i++) 
            cout<<qu[i]<<endl; 
    } 
    else{ 								//else if front is ahead of rear then printing from front to N and then from 0 to rear
        for(int i=front;i<N;i++) 
            cout<<qu[i]<<endl; 
        for(int i=0;i<=rear;i++) 
            cout<<qu[i]<<endl; 
    } 
}
int main(){
    int ch;								//initializing ch as a variable to choose any operation
	while (1){
		cout<<"Choose any Operation from the following:\n";
		cout<<"1) Enqueue\n";
		cout<<"2) Dequeue\n";
		cout<<"3) Display\n";
		cout<<"4) Exit\n";
		cin>>ch;						//switching between various operations
		switch (ch){
			case 1:
				int data;
				cout<<"Enter data:\n";
				cin>>data;
				enqueue(data);
				display();
				break;
			case 2:
                dequeue();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);				//exiting the program if user chooses 4
			default:
				break;
		}	
    }
}