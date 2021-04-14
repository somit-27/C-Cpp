#include<stdio.h>
void main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	int min=b^((a^b)&-(a<b));
	int max=a^((a^b)&-(a<b));
	printf("Maximum is: ");
	printf("%d\n",max);
	printf("Minimum is: ");
	printf("%d",min);
}