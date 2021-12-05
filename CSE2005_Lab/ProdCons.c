#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#define MaxItems 6 // Maximum items a producer can produce or a consumer can consume
#define BufferSize 6 // Size of the buffer
sem_t is_empty;
sem_t is_full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;  
void *producer(void *prod_num){   
    int item=278,i;//taking random item as random number
    for(i = 0; i < MaxItems; i++) {
        item++;
        sem_wait(&is_empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d inserted the item %d at %d\n", *((int *)prod_num),buffer[in],in);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&is_full);
    }
}
void *consumer(void *cons_num){
    int i;   
    for(i = 0; i < MaxItems; i++) {
        sem_wait(&is_full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d removed the item %d from %d\n",*((int *)cons_num),item, out);
        out = (out+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&is_empty);
    }
}
int main(){
    int i;
    pthread_t prod[5],cons[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&is_empty,0,BufferSize);//intially empty is buffer size 
    sem_init(&is_full,0,0);//initially full is 0 as there is no item
    int a[5] = {1,2,3,4,5};
    for(i = 0; i < 5; i++) {
        pthread_create(&prod[i], NULL,producer,(void *)&a[i]);
    }
    for(i = 0; i < 5; i++) {
        pthread_create(&cons[i], NULL,consumer,(void *)&a[i]);
    }
    for(i = 0; i < 5; i++) {
        pthread_join(prod[i], NULL);
    }
    for(i = 0; i < 5; i++) {
        pthread_join(cons[i], NULL);
    }
    return 0;
}