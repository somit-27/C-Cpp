#include<stdio.h>
void main()
{
	unsigned int x;
    scanf("%d",&x);
	unsigned int bits=sizeof(x)*8;
	unsigned int rev=0,i,temp;
	for (i=0;i<bits;i++)
	{
		temp=(x&(1<<i));
		if (temp)
			rev|=(1<<((bits-1)-i));
	}
	printf("%u\n",rev);
}