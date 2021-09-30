#include<iostream>
#include<stdlib.h>
using namespace std;
struct list{                    //creating a structure for node
    int data;                   //creating part of node where data is stored 
    list *next;                 //creating pointer which is part of node where address of next node is stored
}*add;                          //add is the address which always points to the first node
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
int search(int x){             //function for searching an element
    int p=1,check=0;            //initialize p for position and check as flag
    list *pos;                  //creating a pointer 
    for(pos=add;pos!=NULL;pos=pos->next){//using for loop incrementing the pointer untill it becomes NULL 
        if(pos->data==x){       //if data is found
            check=1;            //check as 1 because element is found
            return p;             //return to stop the function
        }
        p++;                    //increase p if not found
    }
    if(check==0){               //after loop if check is 0
        return -1;
    }
    return 0;
}
void del(int x){                //function to delete a node where x is the position of the node to be deleted
    int po=search(x);           //search in list and store position
    if(po!=-1){
        if(add==NULL){              //if first address point to NULL
            cout<<"Linked list is empty"<<endl;//print list is empty
        }
        else if(add->next==NULL&&po==1){//else if there is only 1 node in list
            add=NULL;               //after removing the list becomes empty and first address points to NULL
        }
        else if(add->next!=NULL && po==1){//else if you need to remove 1st element and the linked list has more than one element
            add=add->next;          //first address wil point to address of 2nd node which now becomes 1st
        }
        else{                       //else if we need to remove any node between 2 nodes
            list *pos=add;          //creating a pointer with first address
            list *temp;             //creating a temporary node
            int i;                  //initialize i
            for(i=1;i<po-1;i++){     //using for loop incrementing until pos has address of node prior to the one to be removed
                pos=pos->next;
            }
            temp=pos->next;         //storing the address of node to be deleted in temp
            pos->next=temp->next;   //storing the address of node next to deleted node in pos 
        }
    }
    else{
        cout<<"Element not present in list"<<endl;
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
void replace(){                 //to replace all elemnets with new one
    int data;
    cout<<"Enter elements to replace the previous list"<<endl;
    list *pos;                  //pointer to point at nodes
    for(pos=add;pos!=NULL;pos=pos->next){//for loop to increment nodes
        cin>>data;              //taking input of data
        pos->data=data;         //replcae value in that node
    }
    cout<<"The new linked list is:"<<endl;
    display();
}
int main(){
    add=NULL;                   //first address initialized as NULL because linked list is empty
    int c,data;                 //initialize c for chhosing operations and data for input or removal of data
    while(1){
        cout<<"Choose any Operation from the following:\n";
        cout<<"1) Insert at rear\n";
        cout<<"2) Search\n";
        cout<<"3) Delete an element\n";
        cout<<"4) Display the linked list\n";
        cout<<"5) Replace the linked list\n";
		cout<<"6) Exit\n";
		cin>>c;
        switch (c){             //switch case to choose between functions
    case 1:
            cout<<"Enter data to inserted in linked list at the end:"<<endl;
            cin>>data;
            insend(data);
            break;
        case 2:
            cout<<"Enter the element to be search in linked list:"<<endl;
            cin>>data;
            int pos;
            pos=search(data);
            if(pos!=-1)
            cout<<"The element is found at "<<pos<<endl;
            else
            cout<<"Element not found"<<endl;
            break;
        case 3:
            cout<<"Enter the element to be deleted:"<<endl;
            cin>>data;
            del(data);
            break;
        case 4:
            display();
            break;
        case 5:
            replace();
            break;
        case 6:
            exit(0);            //exiting the program
        default:
            break;
        }
    }
}