#include<stdio.h>
void main()
{
    int hrs,min,amount;
    printf("Enter hors and minutes:");
    scanf("%d%d",&hrs,&min);
    if (hrs>7)
    printf("Hours Exceeded");
    else
    {
        if (hrs>=5)
        {
            amount+=200;
            hrs-=5;
        }
        amount+=hrs*50;
        amount+=min;
        printf("Amount to be paid is %d\n",amount);
    }
}
