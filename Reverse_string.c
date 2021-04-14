#include<stdio.h>
#include<string.h>
char rev(char *n,int l){
    if(l>=0){
        printf("%c",*(n+l));
        return rev(n,--l);
    }
}
int main(){
    char n[100];
    scanf("%s",n);    
    rev(n,strlen(n)-1);
}