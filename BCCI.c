#include<stdio.h>
void main(){
	int n,s1,s2,s3,i,j,fre[20],greater,inde;
	char pl_id,id[20],gr;
	scanf("%d",&n);
	for(j=1;j<20;j++){
		fre[j]=0;
	}
	for(i=1;i<n+1;i++){
		scanf("%s\n%d\n%d\n%d",&pl_id,&s1,&s2,&s3);
		fre[i]=s1+s2+s3;
		id[i]=pl_id;
	}
	greater=fre[1];
	gr=id[1];
	inde=1;
	for(j=1;j<20;j++){
		if(greater<fre[j]){
			greater=fre[j];
			gr=id[j];
			inde=j;
		}
	}
	printf("%c\n",gr);
	printf("%d\n",greater);
	printf("%d",inde);	
}
