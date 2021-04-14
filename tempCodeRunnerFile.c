#include<stdio.h>
#include<math.h>
void main(){
	int n,i,ans=0;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		ans=ans+(arr[i]*pow(10,n-i-1));
	}
	printf("%d",ans);
}