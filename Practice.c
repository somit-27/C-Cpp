#include<stdio.h>
struct player{
     int id;
     char name[10];
     int scores;
};
void bubble(int arr[],int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                int temp;
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}
}
int main(){
    int n,flag=0;
    int a[n];
    scanf("%d",&n);
    struct player p[n];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i].id);
        scanf("%s",p[i].name);
        scanf("%d",&p[i].scores);
        a[i] = p[i].scores;
    }
    for(i=0;i<)
    if(flag==0)
    bubble(a,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==p[j].scores){
                printf("%s %d\n",p[j].name,p[j].id);
                break;
            }
        }
    }
}