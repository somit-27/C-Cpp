#include<stdio.h>
#include<stdlib.h>
int main(){
    int index=0,i,j,k,size1,size2,find;
    printf("Length of reference string:\n");
    scanf("%d",&size1);
    int page[size1];
    printf("Page reference string:\n");
    for(i=0;i<size1;i++){
        scanf("%d",&page[i]);
    }
    printf("Size of frame:\n");
    scanf("%d",&size2);
    int arr[size2],used[size2],flag=0;
    for(i=0;i<size2;i++){
        used[i]=-1;
        arr[i]=-1;
    }
    int page_fault=0;
    for(i=0;i<size1;i++){
        flag=0;
        for(j=0;j<size2;j++){
            if(arr[j]==-1){
                index=j;
                flag=1;
                break;
            }
        }
        for(j=0;j<size2;j++){
            if(used[j]==size2-1 && arr[j]!=-1 && flag==0){
                index=j;
                break;
            }
        }
        find=0;
        for(j=0;j<size2;j++){
            //printf("%d %d   ",arr[j],page[i]);
            if(arr[j]==page[i]){
                find=1;
                used[j]=0;
                for(k=0;k<size2;k++){
                    if(used[k]!=-1 && k!=j){
                        used[k]=(used[k]+1)%size2;
                    }
                }
                //printf("Found %d\n",page[i]);
                break;
            }
        }
        if(find==0){
            page_fault++;
            arr[index]=page[i];
            used[index]=0;
            for(k=0;k<size2;k++){
                if(used[k]!=-1 && k!=index){
                    used[k]=(used[k]+1)%size2;
                }
            }
        }
        for(k=0;k<size2;k++){
            printf("%d",arr[k]);
        }
        printf(" %d\n",index);
    }
    printf("Page Faults:\n%d",page_fault);
}

