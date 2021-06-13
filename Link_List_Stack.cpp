#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *top, *ptr;
void push()
{
    int d;
    node *q=new node;
    if (q==NULL){
        cout<<"Underflow\n";
    }
    else{
        cout<<"Enter data:\n";
        cin>>q->data;
        q->next=NULL;
        if (top==NULL){
            top=q;
        }
        else{
            q->next=top;
            top=q;
        }
    }
}
void pop(){
    if (top==NULL){
        cout<<"underflow\n";
    }
    else if (top->next==NULL){
        top=NULL;
    }
    else{
        top=top->next;
    }
}
void display(){
    node *q;
    for (q=top;q!=NULL;q=q->next)
    {
        cout<<q->data<<" ";
    }
    cout<<"\n";
}
int main(){
    int ch;
    while (1){
        cout<<"Stack operations:\n";
        cout<<"1) Push\n";
        cout<<"2) Pop\n";
        cout<<"3) Display\n";
        cout<<"4) Exit\n";
        cout<<"Enter choice:\n";
        cin>>ch;
        switch(ch){
            case 1:
                push();
                display();
                break;
            case 2:
                pop();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Empty\n";
                break;
        }
    }
    return 0;
}