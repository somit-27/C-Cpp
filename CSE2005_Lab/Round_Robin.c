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
    int sbt[n],bt[n],ar[n],p[n],wt[n],tat[n],index=0,q[n],time=0,ct[n],qt;
    float wt_avg=0,tat_avg=0;
    for(i=0;i<n;i++){
        printf("Enter process %d number, burst time and arrival time:\n ",i+1);
        scanf("%d%d%d",&p[i],&bt[i],&ar[i]);
    }
    printf("Enter quantum time");
    scanf("%d",&qt);
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
    int compl;
    int indi=0;
    compl=0;
    while(compl!=n){
        printf("%d \n",compl);
        for(index=0;index<n;index++){
            if(ar[index]<=time && bt[index]>0){
                if(bt[index]<=qt){
                    time+=bt[index];
                    bt[index]=0;
                    tat[index]=time-ar[index];
                    wt[index]=tat[index]-sbt[index];
                    tat_avg+=(float)tat[index];
                    wt_avg+=(float)wt[index];
                    compl++;
                }
                else{
                    bt[index]-=qt;
                    time+=qt;
                }
            }
        }
    }
    for(index=0;index<n;index++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",p[index],sbt[index],ar[index],wt[index],tat[index]);
    }
    wt_avg/=(float)n;
    tat_avg/=(float)n;
    printf("Average waiting time is %f\n",wt_avg);
    printf("Average turnaround time is %f",tat_avg);
}