#include<stdio.h>
#include<stdlib.h>
int main(){
    int hs,nor,i,sum=0,diff;
    printf("Head Start:\n");
    scanf("%d",&hs);
    printf("Number of Requests:\n");
    scanf("%d",&nor);
    int reqq[nor],used[nor],count=nor;
    printf("Request Queue:\n");
    for(i=0;i<nor;i++){
        scanf("%d",&reqq[i]);
        used[i]=0;
    }
    while(count!=0){
        int min=1000,index;
        for(i=0;i<nor;i++){
            diff=abs(reqq[i]-hs);
            if(diff<min && used[i]==0){
                min=diff;
                index=i;
            }
        }
        sum+=min;
        hs=reqq[index];
        used[index]=1;
        count--;
    }
    printf("%d",sum);
}