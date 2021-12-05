// #include <stdio.h>
// #include <pthread.h>
// void* process(void *s);
// int flag[2];
// int turn,count=0;
// const int final = 1e5;
// void main(){
//     pthread_t parent0,parent1;
//     count=0;
//     flag[0]=flag[1]=0;
//     turn=0;
//     pthread_create(&parent0, NULL, process, (void*)0);
//     pthread_create(&parent1, NULL, process, (void*)1);
//     pthread_join(parent0, NULL);
//     pthread_join(parent1, NULL);
//     printf("The actual count is %d and the expected count is %d\n",count, final*2);
// }
// void lock(int current){                             //this is the algorithm
//     flag[current] = 1;
//     turn = 1-current;
//     while (flag[1-current]==1 && turn==1-current);
// }
// void unlock(int current){
//     flag[current] = 0;
// }
// void* process(void *s){
//     int i = 0;
//     int current = (int *)s;
//     printf("Process : %d\n", current);
//     lock(current);                                  //lock is for giving other parent turn to enter CS and execute
//     for (i=0; i<final; i++)
//         count++;
//     unlock(current);
// }
#include <stdio.h>
#include <pthread.h>

void* process(void *s);
int flag[2];
int turn,count=0,mode=0;
const int MAX = 1e9;

void main()
{
    printf("*** Peterson's Algorithm ***\n");
    pthread_t p1,p2,p3,p4;

    printf("\nFirst without Lock\n");

    pthread_create(&p1, NULL, process, (void*)0);
    pthread_create(&p2, NULL, process, (void*)1);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",count, MAX*2);

    printf("\n\nNow with Lock\n");
    count = 0;
    mode = 1;
    lock_init();

    pthread_create(&p3, NULL, process, (void*)0);
    pthread_create(&p4, NULL, process, (void*)1);

    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    printf("Actual Count: %d | Expected Count: %d\n",count, MAX*2);

}

void lock_init()
{
    flag[0] = flag[1] = 0;
    turn = 0;
}

void lock(int current)
{
    flag[current] = 1;

    turn = 1-current;
    while (flag[1-current]==1 && turn==1-current) ;
}

void unlock(int current)
{
    flag[current] = 0;
}

void* process(void *s)
{
    int i = 0;
    int current = (int *)s;
    printf("Process : %d\n", current);

    if(mode == 1)
        lock(current);
    for (i=0; i<MAX; i++)
        count++;

    if(mode == 1)
        unlock(current);
}