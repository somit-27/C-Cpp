#include<iostream>
#include<stdlib.h>
using namespace std;
struct list{                    //creating a structure for node
    int data;                   //creating part of node where data is stored 
    list *next;                 //creating pointer which is part of node where address of next node is stored
}*add;                          //add is the address which always points to the first node
void insbet(int x,int n){       //function for inserting in between the linked list //n is the position where new node is to be inserted
    int i;                      //initialize i 
    list *t=add;                //creating a temporary pointer and storing it with first node address
    list *temp=new list;        //creating a new node
    temp->data=x;               //storing the data in the node
    for(i=1;i<n-1;i++){         //using for loop increasing temporary pointer so that it points to the node after which new node is to be inserted
        t=t->next;
    }
    temp->next=t->next;         //storing the address of next node to new node 
    t->next=temp;               //stroing the address of new node to previous node
}
void insbeg(int x){             //function for inserting in beginning
    int position=0;
    list *temp;
    for(temp=add;temp!=NULL;temp=temp->next){
      if(temp->data<x){
        position++;
      }
    }
    if(position==0){
      list *temp=new list;        // creating a node
      temp->data=x;               //storing the data entered in that node
      temp->next=add;             //storing the address of the next node in the temporary node
      add=temp;                   //storing address of node in add as it becomes first node
    }
    else{
      insbet(x,position);
    }
}
void search(int x){             //function for searching an element
    
}
int main(){
    add=NULL;                   //first address initialized as NULL because linked list is empty
    int c,data;                 //initialize c for chhosing operations and data for input or removal of data
    while(1){
        cout<<"Choose any Operation from the following:\n";
		    cout<<"1) Insert\n";
        cout<<"2) Search\n";
        cout<<"3) Display the linked list\n";
		    cout<<"4) Exit\n";
		cin>>c;
        switch (c){             //switch case to choose between functions
        case 1:
            cout<<"Enter data to inserted in linked list at the beginning:"<<endl;
            cin>>data;
            insbeg(data);
            break;
        case 2:
          cout<<"Enter the resultant"<<endl;
          cin>>data;
            search(data);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);            //exiting the program
        default:
            break;
        }
    }
}