#include<stdio.h>
#include<stdlib.h>
int main(){
    int hs,nor,i,sum=0;
    printf("Head Start:\n");
    scanf("%d",&hs);
    printf("Number of Requests:\n");
    scanf("%d",&nor);
    int reqq[nor];
    printf("Request Queue:\n");
    for(i=0;i<nor;i++){
        scanf("%d",&reqq[i]);
    }
    sum=abs(reqq[0]-hs);
    for(i=0;i<nor-1;i++){
        sum+=abs(reqq[i]-reqq[i+1]);
    }
    printf("%d",sum);
}