#include<stdio.h>
void main(){
    char m1[3][3],m2[3][3],m3[3][3];
    int i_counter=0,j_counter=0,empty_cells=0,win=0;
    for(i_counter=0;i_counter<3;i_counter++)
    for(j_counter=0;j_counter<3;j_counter++)
        scanf("%d",&m1[i_counter][j_counter]);
    for(i_counter=0;i_counter<3;i_counter++)
    for(j_counter=0;j_counter<3;j_counter++)
        scanf("%d",&m2[i_counter][j_counter]);
    for(i_counter=0;i_counter<3;i_counter++)
    for(j_counter=0;j_counter<3;j_counter++)
        m3[i_counter][j_counter]=m1[i_counter][j_counter]+m2[i_counter][j_counter];
    for(i_counter=0;i_counter<3;i_counter++)
    for(j_counter=0;j_counter<3;j_counter++)
        printf("%d",m3[i_counter][j_counter]);
}