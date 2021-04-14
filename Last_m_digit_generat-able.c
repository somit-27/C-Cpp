#include<stdio.h>
#include<math.h>
int sum(long int s,int n,int m){
    int i;
    int r;
    if(n<m){
        r=(int)(s/pow(10,m-n-1));
        r=r%10;
        return r;
    }
    else{
        r=0;
        for(i=1;i<=m;i++){
            r=r+sum(s,n-i,m);
        }
        return r;
    }
}
int main(){
    int i=0,m,x;
    long long int s=0,n,num=0;
    scanf("%lld%d",&n,&m);
    printf("%dn\n",n);
    for(i=0;i<m;i++){
        int r=(int)(n%10);
        n=n/10;
        s=s+(long long)(r*pow(10,i));
    }
    printf("%ds\n",s);
    while(num<s){
        //printf("%d\n",sum(s,i,m));
        num=sum(s,i,m);
        i++;
    }
    if(num==s){
        printf("Generated");
    }
    else{
        printf("Cannot be generated");
    }
}