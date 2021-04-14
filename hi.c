#include<stdio.h>
#include<stdlib.h>
#include <math.h>
void main()
{
    int acc_details[20],total=0;
    int num_of_days,counter;
    float mean,x;
    scanf("%d\n",&num_of_days);
    for(counter=0;counter<num_of_days;counter++)
    {
        scanf("%d",&acc_details[counter]);
        total+=acc_details[counter];
    }
    mean=total/(float)num_of_days;
    printf("%.2f\n",mean);
    for(counter=0;counter<num_of_days;counter++)
    {
        x=mean-(float)acc_details[counter];
        printf("%.2f\n",fabsf(x));
    }
}