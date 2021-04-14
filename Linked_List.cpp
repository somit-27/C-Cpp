#include<iostream>
#include<stdlib.h>
using namespace std;
struct list{                    //creating a structure for node
    int data;                   //creating part of node where data is stored 
    list *next;                 //creating pointer which is part of node where address of next node is stored
}*add;                          //add is the address which always points to the first node
void insbeg(int x){             //function for inserting in beginning
    list *temp=new list;        // creating a node
    temp->data=x;               //storing the data entered in that node
    temp->next=add;             //storing the address of the next node in the temporary node
    add=temp;                   //storing address of node in add as it becomes first node
}
void insend(int x){             //function for inserting at end
    list *temp=new list;        //creating a new node
    temp->data=x;               //storing data in that node
    temp->next=NULL;            //as it is last node address will be NULL
    if(add==NULL){              //if the linked list was empty 
        add=temp;               //the add will point toward the the new node
        return;
    }
    else{                       //if linked list was not empty
        list *t=add;            //creating a pointer and storing it with first node address
        while(t->next!=NULL){   //incrementing the pointer it untill it points to last node
            t=t->next;
        }
        t->next=temp;           //storing the address of last node to the new node created
    }
}
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
void search(int x){             //function for searching an element
    int p=1,check=0;            //initialize p for position and check as flag
    list *pos;                  //creating a pointer 
    for(pos=add;pos!=NULL;pos=pos->next){//using for loop incrementing the pointer untill it becomes NULL 
        if(pos->data==x){       //if data is found
            cout<<"The element is found at"<<p<<endl;// printing p 
            check=1;            //check as 1 because element is found
            return;             //return to stop the function
        }
        p++;                    //increase p if not found
    }
    if(check==0){               //after loop if check is 0
        cout<<"Element not found"<<endl;// print element is not found
    }
}
void del(int x){                //function to delete a node where x is the position of the node to be deleted
    if(add==NULL){              //if first address point to NULL
        cout<<"Linked list is empty"<<endl;//print list is empty
    }
    else if(add->next==NULL&&x==1){//else if there is only 1 node in list
        add=NULL;               //after removing the list becomes empty and first address points to NULL
    }
    else if(add->next!=NULL && x==1){//else if you need to remove 1st element and the linked list has more than one element
        add=add->next;          //first address wil point to address of 2nd node which now becomes 1st
    }
    else{                       //else if we need to remove any node between 2 nodes
        list *pos=add;          //creating a pointer with first address
        list *temp;             //creating a temporary node
        int i;                  //initialize i
        for(i=1;i<x-1;i++){     //using for loop incrementing until pos has address of node prior to the one to be removed
            pos=pos->next;
        }
        temp=pos->next;         //storing the address of node to be deleted in temp
        pos->next=temp->next;   //storing the address of node next to deleted node in pos 
    }
}
void display(){                 //function to display the linked list
    if(add==NULL){              //if first address is NULL list is empty
        cout<<"The linked list is empty"<<endl;
    }
    else{                       //else 
        list *pos;              //creating a temporary pointer
        for(pos=add;pos!=NULL;pos=pos->next){//using for loop to increment the pos one by one 
            cout<<pos->data<<"\t";//printing the data at the position
        }
    cout<<endl;
    }
}
int main(){
    add=NULL;                   //first address initialized as NULL because linked list is empty
    int c,data;                 //initialize c for chhosing operations and data for input or removal of data
    while(1){
        cout<<"Choose any Operation from the following:\n";
		cout<<"1) Insert at Beginning\n";
        cout<<"2) Insert at End\n";
        cout<<"3) Insert at an position\n";
        cout<<"4) Search\n";
        cout<<"5) Delete an element\n";
        cout<<"6) Display the linked list\n";
		cout<<"7) Exit\n";
		cin>>c;
        switch (c){             //switch case to choose between functions
        case 1:
            cout<<"Enter data to inserted in linked list at the beginning:"<<endl;
            cin>>data;
            insbeg(data);
            break;
        case 2:
            cout<<"Enter data to inserted in linked list at the end:"<<endl;
            cin>>data;
            insend(data);
            break;
        case 3:
            int n;
            cout<<"Enter the position at which data is to be inserted:"<<endl;
            cin>>n;
            cout<<"Enter data to be inserted in linked list at"<< n <<"position:"<<endl;
            cin>>data;
            insbet(data,n);
            break;
        case 4:
            cout<<"Enter the element to be search in linked list:"<<endl;
            cin>>data;
            search(data);
            break;
        case 5:
            cout<<"Enter the position of element to be deleted:"<<endl;
            cin>>data;
            del(data);
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);            //exiting the program
        default:
            break;
        }
    }
}