#include<stdio.h>
#include<stdlib.h>
int n=5;//Number of processes
int m=3;//Number of resources
int main(){
    int i,j,k,l=0,p[n],all[n][m],need[n][m],avail[m],work[m],res[m],ans[n],run[n],compl=0,notavail=0,max2[m];
    for(i=0;i<n;i++){
        run[i]=1;
        printf("Enter process number\n");
        scanf("%d",&p[i]);
        printf("Enter %d allocated resources for process %d\n",m,p[i]);
        for(j=0;j<m;j++){
            scanf("%d",&all[i][j]);
        }
        printf("Enter %d needed resources for process %d\n",m,p[i]);
        for(j=0;j<m;j++){
            scanf("%d",&need[i][j]);
        }
    }
    printf("Enter maximum instances for %d resources\n",m);
    for(i=0;i<m;i++){
        scanf("%d",&res[i]);
        max2[i]=res[i];
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            max2[i]=max2[i]-all[j][i];
        }
        avail[i]=max2[i];
        work[i]=avail[i];
    }
    printf("Process\tAllocated Matrix\tNeeded Matrix\n");
    for(i=0;i<n;i++){
        printf("%d\t",p[i]);
        for(j=0;j<m;j++){
            printf("%d ",all[i][j]);
        }
        printf("\t\t\t");
        for(j=0;j<m;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    printf("Do you need to request any resources 1 for Yes 0 for No:\n");
    int aa;
    scanf("%d",&aa);
    if(aa==1){
        int ab;
        printf("Enter process number which requests:\n");
        scanf("%d",&ab);
        int ac;
        printf("Enter requests for each resource:\n");
        for(i=0;i<m;i++){
            scanf("%d",&ac);
            all[ab][i]+=ac;
            avail[i]-=ac;
            need[ab][i]-=ac;
            work[i]=avail[i];
        }
    }
    printf("Process\tAllocated Matrix\tNeeded Matrix\n");
    for(i=0;i<n;i++){
        printf("%d\t",p[i]);
        for(j=0;j<m;j++){
            printf("%d ",all[i][j]);
        }
        printf("\t\t\t");
        for(j=0;j<m;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    while(compl!=n && notavail!=n-compl+1){
        for(i=0;i<n;i++){
            int count=0;
            for(j=0;j<m;j++){
                if(need[i][j]<=work[j] && run[i]==1){
                    count++;
                }
            }
            if(count==m && run[i]==1){
                for(k=0;k<m;k++){
                    work[k]+=all[i][k];
                    all[i][k]=0;
                }
                ans[l++]=p[i];
                run[i]=0;
                compl++;
            }
            else if(run[i]==1){
                notavail++;
            }
        }
    }
    if(compl==n){
        printf("The processes are in safe state.\n");
        for(i=0;i<n;i++){
            printf("%d->",ans[i]);
        }
        printf("end\n");
    }
    else if(notavail==n-compl+1){
        printf("The processes are in unsafe state.\n");
        for(i=0;i<n;i++){
            printf("%d->",ans[i]);
        }
        printf("end\n");
    }
    return 0;
}