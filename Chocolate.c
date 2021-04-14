#include<stdio.h>
int main()
{
    float n,c;
    int p,m,f,tot;
    printf("Enter amount in hand,price of chocolate and number of free wrappers:");
    scanf("%f%f%d",&n,&c,&m);
    p=(int)(n/c);
    f=(int)(p/m);
    tot=p+f;
    printf("No. of chocolates bought %d\n",tot);
}