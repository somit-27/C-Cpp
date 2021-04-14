#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
int a[100][100],b[100][100],c[100][100],m,n,ch,i,j,t,k;

printf("Enter the choice for matrix arithmetic operation\n");
printf("1 for Addition of matrices\n2 for Subtraction of matrices\n3 for Multiplication of matrices");
printf("\nEnter your choice:");
scanf("%d",&ch);
printf("Enter the value of m & n for the two mxn matrix(in case of multiplication mxn & nxm):");
scanf("%d%d",&m,&n);
printf("\nEnter for 1st matrix\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("\nEnter the number:");
scanf("%d",&a[i][j]);
}
}
if(ch==1||ch==2)
{
printf("\nEnter for 2nd matrix\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("\nEnter the number:");
scanf("%d",&b[i][j]);
}
}
 }
else if(ch==3)
 {
 printf("\nEnter for 2nd matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("\nEnter the number:");
scanf("%d",&b[i][j]);
}
}
 }
    else
{
printf("\nWrong choice entered!!");
getche();
exit(0);
}

printf("\nThe two matrices\n\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n\n");
}
 printf("&\n\n");
if(ch==1||ch==2)
{

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",b[i][j]);
}
printf("\n\n");
}
}
if(ch==3)
{
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",b[i][j]);
}
printf("\n\n");
}
}

if(ch==1)
{
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
 c[i][j]=a[i][j]+b[i][j];
}
}
}
else if(ch==2)
{
 for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
 c[i][j]=a[i][j]-b[i][j];
}
}
}
else if(ch==3)
{

 for(i=0;i<m;i++)
{
for(j=0;j<m;j++)
{
c[i][j]=0;
for(k=0;k<n;k++)
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}

printf("\nThe resultant matrix after multiplication is\n\n");
for(i=0;i<m;i++)
{
for(j=0;j<m;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n\n");
}
getche();
exit(0);
}

printf("\nThe resultant matrix is\n\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n\n");
}
getche();
return 0;
}