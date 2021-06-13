/*Valid Customized Roman Numeral
A teacher wants to give an assignment on Roman numberals. But she is afraid that the students may get the answer from internet. 
Therefore she customizes the roman numerals with changes in the rule of formation. Romans represented numbers using the numerals 
I, V, X, L, C, D, and M as shown in the table:
Roman Numeral    Hindu-Arabic Equivalent
I                   1
V                   5
X                   10
L                   50
C                   100
D                  500
M                  1000

There are a few rules for writing numbers with Roman numerals:
Repeating a numeral represents addition of the number. For example, III represents 1 + 1 + 1 = 3.
Only I, X, C, and M can be repeated that is III is valid but LL is not valid
Writing numerals that decrease from left to right represents addition of the numbers. 
    For example, LX represents 50 + 10 = 60 and XVI represents 10 + 5 + 1 = 16.
Writing numerals that increase from left to right represents subtration. For example, IV represents 5 - 1 = 4 and IX represents 10 - 1 = 9.
Maximum of two same small numerals can only be written to the left of a Roman numeral. For example, 8 can be represented by either VIII or IIX
For example, XXXIX is 39 and XXXXIIX is 48.  IIIIX is invalid. Given a string of roman numeral, write a C++ code to check if it is valid and 
    also print the arabic equivalent if valid and print Invalid otherwise.
More Example
Value of LDMM = 1450

Input Format
First line contains the roman numeral string, s
Output Format
Print the arabic equivalent of s*/
#include<iostream>
#include<stdlib.h>
using namespace std;
int value(char s){
    if(s=='I')
    return 1;
    else if(s=='V')
    return 5;
    else if(s=='X')
    return 10;
    else if(s=='L')
    return 50;
    else if(s=='C')
    return 100;
    else if(s=='D')
    return 500;
    else if(s=='M')
    return 1000;
}
int main(){
    int i,j,k,ans=0,count=0,t;
    char s[50];
    cin>>s;
    for(i=0;s[i]!='\0';i++){
        t=i;
        if((value(s[i])==value(s[i+1]))&&((s[i]=='V')||(s[i]=='L')||(s[i]=='D'))){
            cout<<"Invalid";
            exit(0);
        }
        while(value(s[t])==value(s[t+1])){
            count++;
            t++;
            if(value(s[t])<value(s[t+1])){
                break;
            }
            else if(value(s[t])>value(s[t+1])){
                count=0;
            }
        }
        if(value(s[t])<value(s[t+1])&&(count>2)){
                cout<<"Invalid";
                exit(0);
        }
    }
    for(i=0;s[i]!='\0';i++){
        t=i;
        j=0;
        if(value(s[t])<value(s[t+1])){
            while(value(s[t])<value(s[t+1])){
                ans=ans-value(s[t]);
                j++;
                t++;
            }
            ans=ans+value(s[t]);
            i=t;
        }
        else if((value(s[i])==value(s[i+1]))&&(value(s[i+1])<value(s[i+2]))&&(count<=2)){
            ans=ans-value(s[i])-value(s[i+1])+value(s[i+2]);
            i=i+2;
        }
        else{
            ans=ans+value(s[i]);
        }
    }
    cout<<ans;
}