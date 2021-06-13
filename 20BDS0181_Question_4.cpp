#include<iostream>
#include<stdlib.h>
using namespace std;
struct node{//creating a node
	int data;//data in the node
	node *next;//next pointer in that node
	node *prev;//previous pointer in that node
};
struct node *head = NULL;//head to point
int calclen(){//calculating length of list
	int l=0;
	struct node *ptr=head;
	while(ptr!=NULL){//until ptr becomes NULL or goes till last node
		ptr = ptr->next;//ptr is incremented
		l++;//length incremented
	}
	return l;
}
void isempty(){//to check if it is empty
    if(head==NULL){//if head is at NULL
        cout<<"The list is empty"<<endl;//it is empty
    }
    else{
        cout<<"The list is not empty"<<endl;
    }
}
void insbeg(int d){//insert at beginning
	if(head==NULL){//if list is empty
		struct node *ptr = new node;//create a new node
		ptr->data = d;//entering the data
		ptr->prev = NULL;//both prev and next will be NULL
		ptr->next = NULL;
		head = ptr;//head will point to ptr
	}else{//if not empty
		struct node *ptr = new node;
		ptr->data = d;//enter the data
		ptr->prev = NULL;//previous will be NULL as it is 1st node
		ptr->next = head;//ptr will point to head
		head->prev = ptr;//head previous will now point to ptr
		head = ptr;
	}
}
void insend(int d){//insert at end
	if(head==NULL){//to check if it empty
		cout<<"List is empty"<<endl;
	}else{
		struct node *ptr = head;//create a pointer
		struct node *newnode = new node;//create a node
		while(ptr->next!=NULL){//increment ptr until last of list
			ptr = ptr->next;
		}
		newnode->data = d;//enter the data in node
		newnode->next = NULL;//next will be NULL as it is last node
		ptr->next = newnode;//ptr will point towards the new node
		newnode->prev = ptr;//previous of new node will point to ptr
	}
}
void del(int d){//deleting 
	int len = calclen();//calculating length
	if(head==NULL){//if it is empty
		cout<<"List is empty"<<endl;
	}else{
		int pos=1,check=0,i,flag=0;//same as search to find the position of the element
        struct node *ptr=head;
        for(i=0;ptr!=NULL;i++){
            if(ptr->data==d){
                pos=i+1;
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            ptr=ptr->next;
        }
        if(flag==1){//if element not found
            cout<<"Element not present"<<endl;
        }
		else if(pos==1 && head->next==NULL){//if only 1 element is present
			cout<<"The deleted element is "<<head->data<<endl;//output the element
			head=NULL;//head becomes NULL
			cout<<"The list is empty now"<<endl;//list becomes empty
		}else if(pos==1){//if 1st node is to be deleted
			cout<<"The deleted element is "<<head->data<<endl;//output element
			head = head->next;//head will now point to next of it previous position i.e previously 2nd node
			head->prev = NULL;//previous of head will point to NULL
		}
		else if(pos==len){//if it is the last element
				struct node *ptr = head;//create pointer
				struct node *newnode;//create new node
				for(int i=0;i<pos-2;i++){//pointer now points to the node previous to one to be deleted
					ptr = ptr->next;
				}
				newnode = ptr->next;//new node will now point to the node to be deleted
				ptr->next = NULL;//ptr will now point to NULL
				newnode->prev = NULL;//new node previous will point to NULL
				cout<<"The deleted element is "<<newnode->data<<endl;//output the element
			}else{//else if it is somewhere in between
			struct node *ptr = head;
			struct node *newnode;
			for(int i=0;i<pos-2;i++){//pointer now points to the node previous to one to be deleted
				ptr = ptr->next;
			}
			newnode = ptr->next;//new node will now point to the node to be deleted
			newnode->next->prev = ptr;//new node's next node's previous will point to ptr
			ptr->next = newnode->next;//ptr will point to newnode's next node
			cout<<"The deleted element is "<<newnode->data<<endl;//ouput the element
		}
	}
}
void display(){//to display
	if(head==NULL){//if empty
		cout<<"List is empty"<<endl;
	}else{
		cout<<"The elements of list are: "<<endl;
		struct node *ptr = head;//create a pointer
		while(ptr!=NULL){//while ptr is not null
			cout<<ptr->data<<",";//output data
			ptr = ptr->next;//increment ptr
		}
		cout<<"NULL";
		cout<<endl;
	}
}
void search(int d){//to search 
	if(head==NULL){//if empty
		cout<<"List is empty"<<endl;
	}
    else{//else
		int flag=0,i;
		node *ptr = head;   
		for(i=0;ptr!=NULL;i++){//for loop until list ends
			if(ptr->data==d){//if found
				cout<<"Item found at position "<<i+1<<endl;//print position
				flag=0; 
				break; 
			}
			else{
				flag=1; //if not found
			}
			ptr = ptr->next;   //increment ptr
		}
		if(flag==1){//if not found
			cout<<"Item not found"<<endl;
		}
	}
}
int main(){
	int choice,value;     //choice for chhosing between menu and value to pass argument
	do{ //creating a menu driven program
		cout<<"***************"<<endl;
		cout<<"___DOUBLY LINKED LIST OPERATIONS___"<<endl;
        cout<<"1. Check if it is empty"<<endl;
		cout<<"2. Insert at the beginning"<<endl;
		cout<<"3. Insert at the end"<<endl;
		cout<<"4. Delete"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Search"<<endl;
		cout<<"7. Exit...."<<endl;
		cout<<"***************"<<endl;
		cout<<"Enter your choice....."<<endl;
		cin>>choice;     
		switch(choice){
            case 1:{
                isempty();
                break;
            }
			case 2:{
				cout<<"Enter the value to be inserted at the beginning"<<endl;
				cin>>value;
				insbeg(value);     
				break;
			}
			case 3:{
				cout<<"Enter the value to be inserted at the end"<<endl;
				cin>>value;
				insend(value);     
				break;
			}
			case 4:{
                cout<<"Enter the value to be deleted"<<endl;
                cin>>value;
				del(value);            
				break;
			}
			case 5:{
				display();       
				break;
			}
			case 6:{
                cout<<"Enter the value to be searched"<<endl;
		        cin>>value;
                search(value);       
				break;
			}
			case 7:{
                exit(0);
				break;
			}
			default:{
				cout<<"Entered the wrong choice!!!"<<endl;
				break;
			}
			}
		}while(choice);
	return 0;
}