#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
int main(){
    int n,i,j;
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    int sbt[n],bt[n],ar[n],p[n],pr[n],wt[n],tat[n],index=0,q[n],time=0,ct[n],compl=0,st[n];
    float wt_avg=0,tat_avg=0;
    for(i=0;i<n;i++){
        printf("Enter process %d number, burst time, arrival time and priority:\n ",i+1);
        scanf("%d%d%d%d",&p[i],&bt[i],&ar[i],&pr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(ar[j]>ar[j+1]){
                swap(&ar[j],&ar[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
            }
        }
    }
    for(i=0;i<n;i++){
        sbt[i]=bt[i];
        tat[i]=0;
        wt[i]=0;
        ct[i]=0;
    }
    printf("process\tburst_time\tarrival_time\twaiting_time\tturnaround_time\n");
    while(compl!=n){
        int x=-1;
        int prior=10000;
        for(i=0;i<n;i++){
            if(ar[i]<=time && bt[i]>0 && pr[i]<=prior){
                prior=pr[i];
                x=i;
            }
        }
        bt[x]--;
        if(bt[x]==0){
            compl++;
            wt[x]=time+1-ar[x]-sbt[x];
            tat[x]=time+1-ar[x];
            tat_avg+=tat[x];
            wt_avg+=wt[x];
            time++;
        }
        else{
            time++;
        }
    }
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i],sbt[i],ar[i],wt[i],tat[i]);
    }
    wt_avg/=(float)n;
    tat_avg/=(float)n;
    printf("Average waiting time is %f\n",wt_avg);
    printf("Average turnaround time is %f",tat_avg);
}