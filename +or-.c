#include<stdio.h>
void main()
{
	int a,b=1;
	scanf("%d",&a);
	if ((a^b)<0)
	{
		printf("Negative");
	}
	else
	{
		printf("Positive");
	}
}