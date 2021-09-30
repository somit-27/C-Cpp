#include<iostream>
#include <string.h>
using namespace std;
class String{
    public:
    char word1[30],word2[30];
};
class anagram:public String{
    public:
    bool check(){
        int i;
        int l1=strlen(word1);
        int l2=strlen(word2);
        if (l1!=l2){
            return false;
        }
        int a1[26]={0},a2[26]={0};
        for(i=0;word1[i]!='\0';i++){
            a1[word1[i]-'a']++;
        }
        for(i=0;word2[i]!='\0';i++){
            a2[word2[i]-'a']++;
        }
        for(i=0;i<26;i++){
            if(a1[i]!=a2[i]){
                return false;
            }
        }
        return true;
    }
};
class Count:public String{
    public:
    void check(){
        char word[60];
        strcat(word,word1);
        strcat(word,word2);
        int a=0,e=0,I=0,o=0,u=0;
        int l1=strlen(word);
        for(int i=0;i<l1;i++){
            if((word[i]=='a')||(word[i]=='A')){
                a++;
            }
            else if((word[i]=='e')||(word[i]=='E')){
                e++;
            }
            else if((word[i]=='i')||(word[i]=='I')){
                I++;
            }
            else if((word[i]=='o')||(word[i]=='O')){
                o++;
            }
            else if((word1[i]=='u')||(word1[i]=='U')){
                u++;
            }
        }
        cout<<a+e+I+o+u<<endl;
        if(a!=0){
            cout<<"a "<<a<<endl;
        }
        if(e!=0){
            cout<<"e "<<e<<endl;
        }
        if(I!=0){
            cout<<"i "<<I<<endl;
        }
        if(o!=0){
            cout<<"o "<<o<<endl;
        }
        if(u!=0){
            cout<<"u "<<u<<endl;
        }
    }
};
int main(){
    anagram a;
    Count c;
    char str1[30],str2[30];
    cin>>str1>>str2;
    strcpy(a.word1,str1);
    strcpy(a.word2,str2);
    strcpy(c.word1,str1);
    strcpy(c.word2,str2);
    if(a.check()){
        cout<<"Yes"<<endl;
        c.check();
    }
    else{
        cout<<"No";
    }
return 0;
}