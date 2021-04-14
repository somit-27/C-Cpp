#include<stdio.h>
#include<conio.h>
int main()
{
int a[100][100],n,s=0,i,j;
printf("Enter the value of n for nxn matrix:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("\nEnter the number:");
scanf("%d",&a[i][j]);
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i==j)
s=s+a[i][j];
if((i+j)==(n-1))
s=s+a[i][j];
}
}

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n\n");
}
    printf("\n\nThe sum of the diagonal element of the above matrix is %d",s);

getche();
return 0;
}