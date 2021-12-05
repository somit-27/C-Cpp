#include<stdio.h>
#include<stdlib.h>
void main(){
    int index=0,i,j,k,size1,size2;
    printf("Length of reference string:\n");
    scanf("%d",&size1);
    int page[size1];
    printf("Page reference string:\n");
    for(i=0;i<size1;i++){
        scanf("%d",&page[i]);
    }
    printf("Size of frame:\n");
    scanf("%d",&size2);
    int arr[size2],used[size2];
    for(i=0;i<size2;i++){
        arr[i]=-1;
    }
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
            //printf("fault");
            int stop=0;
            int var=0;
            for(j=0;j<size2;j++){
                used[j]=0;
            }
            for(j=i+1;j<size1 && stop==0;j++){
                for(k=0;k<size2 && stop==0;k++){
                    if(page[j]==arr[k] && used[k]==0){
                        used[k]=1;
                        var++;
                        //printf("yes %d %d",arr[k],page[j]);
                    }
                    if(var==size2-1 || j==size1-1){
                        int l;
                        for(l=0;l<size2;l++){
                            if(used[l]==0){
                                index=l;
                                stop=1;
                                break;
                            }
                        }
                    }
                }
            }
            for(j=0;j<size2;j++){
                if(arr[j]==-1){
                    index=j;
                    break;
                }
            }
            arr[index]=page[i];
        }
        for(k=0;k<size2;k++){
            printf("%d ",arr[k]);
        }
        printf("\n");
    }
    printf("Page Faults:\n%d",page_fault);
}

