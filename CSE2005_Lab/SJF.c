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
    int sbt[n],bt[n],ar[n],p[n],wt[n],tat[n],index=0,rq[n],time=0,ct[n],mini,min;
    float wt_avg=0,tat_avg=0;
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
    for(i=0;i<n;i++){
        sbt[i]=bt[i];
        if(bt[index]<bt[i]){
            index=i;
        }
        tat[i]=0;
        wt[i]=0;
        ct[i]=0;
    }
    //printf("%d\n",bt[index]);
    printf("process\tburst_time\tarrival_time\twaiting_time\tturnaround_time\n");
    while(bt[index]!=0){
        mini=100000;
        for(i=0;i<n;i++){
            if(ar[i]<=time && bt[i]<mini && bt[i]!=0){
                mini=bt[i];
                min=i;
            }
        }
        //printf("%d\n",bt[min]);
        ct[min]=time+bt[min];
        time+=bt[min];
        bt[min]=0;
        tat[min]=ct[min]-ar[min];
        wt[min]=tat[min]-sbt[min];
        wt_avg+=(float)wt[min];
        tat_avg+=(float)tat[min];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",p[min],sbt[min],ar[min],wt[min],tat[min],ct[min]);
    }
    wt_avg/=(float)n;
    tat_avg/=(float)n;
    printf("Average waiting time is %f\n",wt_avg);
    printf("Average turnaround time is %f",tat_avg);
}