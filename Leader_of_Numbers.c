#include<stdio.h>
int main(){
    int n;
    scanf("%d\n",&n);
    int arr[n],i,j,d,e=0;
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        d=0;
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                d+=1;
            }
        }
        if(d==n-i-1){
            printf("%d\n",arr[i]);
            e+=1;
        }
    }
    if(e==0){
        printf("No Leaders");
    }
}