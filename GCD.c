#include<stdio.h>
void main()
{
    int x,y;
    int divi,div,rem;
    scanf("%d\n%d",&x,&y);
    divi=x;
    div=y;
    do
    {
        rem=divi%div;
        divi=div;
        div=rem;
    } while (divi%div!=0);
    printf("GCD is %d",div);
}
