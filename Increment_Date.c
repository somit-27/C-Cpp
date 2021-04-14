#include<stdio.h>
#include<string.h>
struct date{
    int mm;
    int dd;
    int yyyy;
};
int main(){
    struct date d;
    scanf("%d%d%d",&d.mm,&d.dd,&d.yyyy);
    if((d.yyyy%4==0&&d.yyyy%100!=0)||(d.yyyy%400==0)){
        if(d.mm==02){
            if(d.dd<29){
                d.dd+=1;
            }
            else if(d.dd==29){
                d.dd=01;
                d.mm+=1;
            }
        }
    }
    else{
        if(d.mm==02){
            if(d.dd<28){
                d.dd+=1;
            }
            else if(d.dd==28){
                d.dd=01;
                d.mm+=1;
            }
    }
    if(d.mm==01||d.mm==03||d.mm==05||d.mm==07||d.mm==8||d.mm==10){
        if(d.dd<31){
            d.dd+=1;
        }
        else if(d.dd==31){
            d.dd=01;
            d.mm+=1;
        }
    }
    else if(d.mm==12){
        if(d.dd<31){
            d.dd+=1;
        }
        else if(d.dd==31){
            d.dd=01;
            d.mm=01;
            d.yyyy+=1;
        }
    }
    else{
        if(d.dd<30){
            d.dd+=1;
        }
        else if(d.dd==30){
            d.dd=01;
            d.mm+=1;
        }
    }
    printf("Tomorrow's Date is:%02d/%02d/%d",d.mm,d.dd,d.yyyy);
}}