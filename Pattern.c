/*#include <stdio.h>
int main() 
{
    int n,len,i,j;
    scanf("%d", &n);
    len=2*n-1;
  	for(i=0;i<len;i++){
    for(j=0;j<len;j++){
        int min=i<j?i:j;
        min=min<len-i?min:len-i-1;
        min=min<len-j-1?min:len-j-1;
        printf("%d ",n-min);
        }
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
int main(){
    int n,i,j,k=0,count=0,countk=0;
    printf("Enter n");
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        for(j=1;j<=n-i;++j){
            printf("  ");
            ++count;
        }
        while(k!=2*i-1){
            if(count<=n-1){
                printf("%d ",i+k);
                ++count;
            }
            else{
                ++countk;
                printf("%d ",(i+k-2*countk));
            }
            ++k;
        }
        countk=count=k=0;
        printf("\n");
    }
}*/
#include<stdio.h>
int main(){
    int i,j,k,n,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=1;j<=n-i;j++){
            printf("  ");    
        }
        for(k=0;k<=i;k++){
            if(i==0||k==0){
                x=1;
            }
            else{
                x=x*(i-k+1)/k;
            }
            printf("%4d ",x);
        }
        printf("\n");
    }
}