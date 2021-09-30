#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y){
    int t=*x;
    *x=*y;
    *y=t;
}
void main(){
    int n,i,j;
    float wt_avg=0,tat_avg=0;
    printf("Enter number of processes:\n");
    scanf("%d",&n);
    int bt[n],ar[n],p[n],flag[n],wt[n],tat[n],temp[n];
    for(i=0;i<n;i++){
        printf("Enter process %d number, burst time and arrival time:\n ",i+1);
        scanf("%d%d%d",&p[i],&bt[i],&ar[i]);
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
    temp[0]=0;
    printf("process\tburst_time\tarrival_time\twaiting_time\tturnaround_time\n");
    for(i=0;i<n;i++){
        tat[i]=0;
        wt[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-ar[i];
        tat[i]=wt[i]+bt[i];
        wt_avg+=wt[i];
        tat_avg+=tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",p[i],bt[i],ar[i],wt[i],tat[i]);
    }
    wt_avg/=n;
    tat_avg/=n;
    printf("Average waiting time is %f\n",wt_avg);
    printf("Average turnaround time is %f",tat_avg);
}