#include<iostream>
#include<stdlib.h>
using namespace std;
int front=-1,rear=-1;			//initialzing front and rear as -1 as base condition as queue is empty
int qu[5];						//initializing a queue of max length 10
int SIZE=5;					//storing the maximum length in a variable
int enqueue(int x){				//function for entring an element in queue
    if(front==-1){				//incrementing the front from its base condition 
        front++;
    }
    if(rear==SIZE-1){			//checking the condition if the queue is full
        cout<<"Queue is full.";
    }
    else{						//else storing the value in rear and then incrementing the rear
        qu[++rear]=x;
    }
}
int dequeue(){					//function to remove an element from queue and then shifting the whole queue behind by 1 index
    if(front==-1 && rear==-1){	//checking if queue is empty
		cout<<"The queue is empty"<<endl;
	}
	else if(front==rear){		//checking the condition if only 1 element if there in queue and removing the element
		cout<<"The removed element is: "<<qu[0]<<endl;		
		front=rear=-1;			//then intializing front and rear as -1 as queue is gaian empty
	}
	else{
		int i;					
    	cout<<"The removed element is:"<<qu[0]<<endl;
    	for(i=front;i<=rear;i++){//shifting every element one index behind as first element is removed
        	qu[i]=qu[i+1];
    	}
    	rear--;					//decrementing rear as then last element is shifted one index back
	}
}
void display(){
	if(front==-1 && rear==-1){	//checking if queue is empty
		cout<<"The queue is empty"<<endl;
	}
	else{			
    	int i;					//printing the elements from front to end
    	cout<<"The values in stack are"<<endl;
    	for(i=front;i<=rear;i++){
        	cout<<i<<"\t"<<qu[i]<<endl;
    	}
	}
}
int main(){
    int ch;						//initializing ch as a variable to choose any operation
	while (1){				//repeating the whole thing until loop if any number other than 1
		cout<<"Choose any Operation from the following:\n";
		cout<<"1) Enqueue\n";
		cout<<"2) Dequeue\n";
		cout<<"3) Display\n";
		cout<<"4) Exit\n";
		cin>>ch;
		switch (ch)				//switch case to check which operation is to be done
		{
			case 1:
				int data;
				cout<<"Enter data:\n";
				cin>>data;
				enqueue(data);
				break;
			case 2:
				dequeue();
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