#include<stdlib.h>
#include<stdio.h>
struct dob{
    int dd;
    int mm;
    int yyyy;
};
struct emp{
    int id;
    char name[20];
    struct dob date;
    long int mob;
};
int main(){
    struct emp* ptr;
    int i,n;
    printf("Enter number of employess:");
    scanf("%d",&n);
    ptr=(struct emp*)malloc(n*sizeof(struct emp));
    for(i=0;i<n;i++){
        printf("Enter details for person %d",i);
        scanf("%d%s",&(ptr+i)->id,(ptr+i)->name);
        scanf("%d%d%d",&(ptr+i)->date.dd,&(ptr+i)->date.mm,&(ptr+i)->date.yyyy);
        scanf("%ld",&(ptr+i)->mob);
    }
    for(i=0;i<n;i++){
        //printf("%s\t%ld\n",(ptr+i)->name,(ptr+i)->mob);
        if((((ptr+i)->date.yyyy<2010)||((ptr+i)->date.yyyy<=2009&&(ptr+i)->date.mm<=12))&&((ptr+i)->id%5==0)){
            printf("%s\t%ld\n",(ptr+i)->name,(ptr+i)->mob);
        }
    }
}