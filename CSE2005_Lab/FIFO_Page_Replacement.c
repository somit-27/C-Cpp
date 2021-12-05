#include<stdio.h>
#include<stdlib.h>
void main(){
    int index=0,i,j,size1,size2;
    printf("Length of reference string:\n");
    scanf("%d",&size1);
    int page[size1];
    printf("Page reference string:\n");
    for(i=0;i<size1;i++){
        scanf("%d",&page[i]);
    }
    printf("Size of frame:\n");
    scanf("%d",&size2);
    int arr[size2];
    int page_fault=0;
    for(i=0;i<size1;i++){
        int find=0;
        for(j=0;j<size2;j++){
            if(arr[j]==page[i]){
            find=1;
            //printf("Found %d\n",page[i]);
            break;
            }
        }
        if(find==0){
            page_fault++;
            arr[index]=page[i];
            index=(index+1)%size2;
        }
    }
    printf("Page Faults:\n%d",page_fault);
}

