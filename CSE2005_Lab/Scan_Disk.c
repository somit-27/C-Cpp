#include<stdio.h>
#include<stdlib.h>
int main(){
    int hs,nor,i,sum=0,small=0,ths1,t,index,k;
    printf("Head Start:\n");
    scanf("%d",&hs);
    ths1=hs;
    printf("Number of Requests:\n");
    scanf("%d",&nor);
    int reqq[nor+1],used[nor];
    printf("Request Queue:\n");
    for(i=0;i<nor;i++){
        scanf("%d",&reqq[i]);
        used[i]=0;
        if(reqq[i]<hs){
            small++;
        }
    }
    //printf("small %d big %d \n",small,big);
    //arrange the array according to direction
    int j=0;
    while (small!=0){
        int min=1000;
        for(i=0;i<nor;i++){
            if(reqq[i]<ths1 && abs(reqq[i]-hs)<min && used[i]==0){
                index=i;
                min=abs(reqq[i]-hs);
            }
        }
        t=reqq[index];
        reqq[index]=reqq[j];
        reqq[j]=t;
        hs=reqq[index];
        used[j]=1;
        //printf("small ka %d  %d\n",reqq[j],j);
        j++;
        small--;
    }
    reqq[j++]=0;
    for(i=j;i<nor;i++){
        for(k=i+1;k<nor;k++){
            if(reqq[i]>reqq[k]){
                t=reqq[i];
                reqq[i]=reqq[k];
                reqq[k]=t;
            }
        }
    }
    sum=abs(reqq[0]-ths1);
    for(i=0;i<nor-1;i++){
        sum+=abs(reqq[i]-reqq[i+1]);
    }
    // for(i=0;i<nor;i++){
    //     printf("%d ",reqq[i]);
    // }
    printf("\n%d",sum);
}