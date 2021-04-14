#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{
    int data;
    node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue(int x){				
    node *q=new node;
    q->data=x;
    q->next=NULL;
    if(front==NULL){
        front=q;
        rear=q;
        rear->next=NULL;
    }
    else{
        rear->next=q;
        rear=q;
        rear->next=NULL;
    }
}
void dequeue(){					
    node *p=front;
    int x;
    if(front==NULL){	        
		cout<<"Underflow"<<endl;
	}
	else if(front==rear){		
        x=p->data;
    	cout<<"The removed element is: "<<x<<endl;		
		front=rear=NULL;			
	}
	else{
        x=p->data;					
    	cout<<"The removed element is:"<<x<<endl;
    	front=front->next;
	}
}
void display(){
	if(front==NULL && rear==NULL){	
		cout<<"The queue is empty"<<endl;
	}
	else{								
    	cout<<"The values in stack are"<<endl;
        node *p=front;
    	while(p!=NULL){
        	cout<<p->data<<"\t";
            p=p->next;
    	}
	}
    cout<<endl;
}
int main(){
    int ch;						
	while (1){				
		cout<<"Choose any Operation from the following:\n";
		cout<<"1) Enqueue\n";
		cout<<"2) Dequeue\n";
		cout<<"3) Display\n";
		cout<<"4) Exit\n";
		cin>>ch;
		switch (ch)				
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