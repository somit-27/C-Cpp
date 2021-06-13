#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
char infix[100],postfix[100],prefix[100];       //initializing 3 arrays of infix, postfix and prefix
#define size 100                                //defining size 
char stack[size];                               //initializing stack
int top=-1;                                     //initializing top as -1 for keeping track in stack
void push(char c){                              //pushing in stack
    if(top==size-1){                            //if stack is full
        cout<<"Overflow"<<endl;                 
    }
    else{
        stack[++top]=c;                         //if not full increment top and then store character
    }
}
char pop(){                                     //popping form stack
    if(size==-1){                               //if stack is empty
        cout<<"Underflow"<<endl;
    }
    else{
        return stack[top--];                    //else return the top element and then decrement top
    }
}
int findPrecedence(char c){                     //returning value as per precedence
    if (c=='^'){                                
        return 3;
    }
    else if ((c=='/')||(c=='*')){
        return 2;
    }
    else if ((c=='+')||(c=='-')){
        return 1;
    }
}
void infix_to_postfix(){
    int i=0,j=0;
    while(infix[i]!='\0'){                      //while infix is not finished
        if (isalpha(infix[i])||isdigit(infix[i])){//if it is a digit or alphabet
            postfix[j++]=infix[i];              //directly push into postfix
        }
        else if((infix[i]=='+')||(infix[i]=='-')||(infix[i]=='*')||(infix[i]=='/')||(infix[i]=='^')||(infix[i]=='(')){//if any operator comes
            if(top==-1){                        //if stack is empty push into stack
                push(infix[i]);
            }
            else if(stack[top]!='('){           //if not empty and top element is not open bracket
                while((findPrecedence(stack[top])>=findPrecedence(infix[i]))&&(stack[top]!='(')){//if precedence of top is greater 
                    postfix[j++]=pop();         //pop the top and store in postfix
                }
                push(infix[i]);                 //push in stack when while loop is done
            }
            else{
                push(infix[i]);                 //else push into stack
            }
        }
        else if ((infix[i]==')')){              //if closing bracket comes
            while(stack[top]!='('){             //empty the stack until open bracket is reached and store in postfix
                postfix[j++]=pop();             
            }
            pop();                              //pop the open bracket
        }
        i++;                                    //increment i
    }   
    while(top!=-1){                             //pop all elements from stack
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
void infix_to_prefix(){                         
    int i=0,j=0;                                
    int l=strlen(infix);                        //finding length of infix
    for(i=0;i<l/2;i++){                         //reversing the infix expression
        int t;
        t=infix[i];
        infix[i]=infix[l-i-1];
        infix[l-i-1]=t;
    }
    for(i=0;i<l;i++){                           //exchange '(' by ')' and vice cersa
        if(infix[i]=='('){
            infix[i]=')';
        }
        else if(infix[i]==')'){
            infix[i]='(';
        }
    }
    infix_to_postfix();                         //convert to postfix
    l=strlen(postfix);                          //find length of postfix
    for(i=0;i<l;i++){                           //reverse postfix and store in prefix
        prefix[i]=postfix[l-i-1];
    }
    prefix[i]='\0';
}
int main(){
    cout<<"Enter an expression"<<endl;           //enter an expression
    cin>>infix;
    infix_to_postfix();
    cout<<"Postfix Expression: "<<postfix<<endl;
    infix_to_prefix();
    cout<<"Prefix Expression: "<<prefix;
}