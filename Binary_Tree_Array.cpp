#include<iostream>
#include<stdlib.h>
using namespace std;
char tree[10];
void root(char alpha){
    if(tree[1]=='\0'){
        tree[1]=alpha;
    }
    else{
        cout<<"The root is already present in the tree"<<endl;
    }  
}
void left(char alpha,int pos){
    if(tree[pos]=='\0'){
        cout<<"Child cannot be inserted"<<endl;
    }
    else{
        tree[2*pos]=alpha;
    }
}
void right(char alpha,int pos){
    if(tree[pos]=='\0'){
        cout<<"Child cannot be inserted"<<endl;
    }
    else{
        tree[2*pos+1]=alpha;
    }
}
void display(){
    int i;
    for(i=1;i<=10;i++){
        if(tree[i]!='\0'){
            cout<<tree[i]<<" ";
        }
        else{
            cout<<"_"<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int i;
    for(i=0;i<10;i++){
        tree[i]='\0';
    }
    char c;
    int pos;
    char al;
    while(1){
        cout<<"Following are the options"<<endl;
        cout<<"R: Insert parent root of tree"<<endl;
        cout<<"l: Insert left node of the parent"<<endl;
        cout<<"r: Insert right node of the parent"<<endl;
        cout<<"d: Display the tree"<<endl;
        cout<<"e: Exit"<<endl;
        cin>>c;
        switch (c){
        case 'R':
            cout<<"Enter element"<<endl;
            cin>>al;
            root(al);
            break;
        case 'l':
            cout<<"Enter element"<<endl;
            cin>>al;
            cout<<"Enter the position of parent node"<<endl;;
            cin>>pos;
            left(al,pos);
            break;
        case 'r':
            cout<<"Enter element"<<endl;
            cin>>al;
            cout<<"Enter the position of parent node"<<endl;
            cin>>pos;
            right(al,pos);
            break;
        case 'd':
            display();
            break;
        case 'e':
            exit(0);
        }
    }
}