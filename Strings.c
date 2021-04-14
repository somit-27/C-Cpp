#include<stdio.h>
int main(){
    char a[]={'h','e'};
    char b[]={"hello\0"};
    printf("%s\n%s",a,b);
    return 0;
}