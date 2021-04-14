#include<stdio.h>
void main()
{
    int m;
    scanf("%d",&m);
    if ((m>=0)&&(m<=100))
    {
        if (m>=90)
        printf("A");
        else if (m>=80)
        printf("B");
        else if (m>=70)
        printf("C");
        else if (m>=60)
        printf("D");
        else if (m>=50)
        printf("E");
        else
        {
            printf("Fail");
        }
    }
    else
    {
        printf("Enter valid marks");
    }    
}
