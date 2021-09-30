#include<iostream>
using namespace std;
int answer(int *arr, int n, int max2){
    int max1=0,i;
    for(i=0;i<n;i++){
        max1=max1+arr[i];
        if(max2<max1){
            max2=max1;
        }
        if(max1<0){
            max1=0;
        }
    }
    return max2;
}
int main(){
    int i,n,max2=-10000000,ans;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
        if(max2<arr[i]){
            max2=arr[i];
        }
    }
    ans=answer(arr,n,max2);
    cout<<ans;
}