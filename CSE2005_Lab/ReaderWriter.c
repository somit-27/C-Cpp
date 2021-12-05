#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t writing;
pthread_mutex_t mutex;
int count=1;
int reader_number=0;
void *writer(void *wr){
    sem_wait(&writing);
    count=count+2;
    printf("Writer %d changed count to %d\n",(*((int *)wr)),count);
    sem_post(&writing);
}
void *reader(void *re){
    pthread_mutex_lock(&mutex);
    reader_number++;
    if(reader_number==1){
        sem_wait(&writing);
    }
    pthread_mutex_unlock(&mutex);
    printf("Reader %d reads the count as %d\n",*((int *)re),count);
    pthread_mutex_lock(&mutex);
    reader_number--;
    if(reader_number==0){
        sem_post(&writing);
    }
    pthread_mutex_unlock(&mutex);
}
void main(){
    int i;
    pthread_t read[8],write[4];
    pthread_mutex_init(&mutex,0);
    sem_init(&writing,0,1);
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    for(i=0;i<8;i++){
        pthread_create(&read[i],NULL,reader,(void *)&a[i]);
    }
    for(i=0;i<4;i++){
        pthread_create(&write[i],NULL,writer,(void *)&a[i]);
    }
    for(i=0;i<8;i++) {
        pthread_join(read[i],NULL);
    }
    for(i=0;i<4;i++) {
        pthread_join(write[i],NULL);
    }

}