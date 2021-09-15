#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include <unistd.h>     // for sleep()
#include <algorithm>    // for fill_n()
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

using namespace std;


// TRAIN CIRCUITS THAT'LL BE CALLED BY THE THREADS
void* train1_execution(void *w);
void* train2_execution(void *w);
void* train3_execution(void *w);
void* train4_execution(void *w);
void L(int path_id, int train, MainWindow *w); // function that represents the passage over the L part of the circuit (its ID as a number)

// MUTEX DEFINITIONS AS GLOBAL
pthread_mutex_t mutex_train12;   // mutex for train 1 and 2 intersection
pthread_mutex_t mutex_train23;   // mutex for train 2 and 3 intersection

pthread_mutex_t mutex_L4L6L10;


// TRAIN VELOCITY ARRAY
int train_velocity[4] = {1, 1, 1, 1};

sem_t semaphoreL3, semaphoreL4, semaphoreL5, semaphoreL6, semaphoreL10;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    int failure;    // the flag for the pthread functions return codes
    // TRAIN THREADS DEFINITIONS
    pthread_t train1, train2, train3, train4;

    // initializing semaphore
    failure = sem_init(&semaphoreL3, 0, 1);
    if(failure)
        exit(EXIT_FAILURE);
    failure = sem_init(&semaphoreL4, 0, 1);
    if(failure)
        exit(EXIT_FAILURE);
    failure = sem_init(&semaphoreL5, 0, 1);
    if(failure)
        exit(EXIT_FAILURE);
    failure = sem_init(&semaphoreL6, 0, 1);
    if(failure)
        exit(EXIT_FAILURE);
    failure = sem_init(&semaphoreL10, 0, 1);
    if(failure)
        exit(EXIT_FAILURE);

    // initializing the mutexes
    failure = pthread_mutex_init(&mutex_train12, NULL);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_mutex_init(&mutex_train23, NULL);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_mutex_init(&mutex_L4L6L10, NULL);
    if(failure)
        exit(EXIT_FAILURE);

    // initializing th threads
    failure = pthread_create(&train1, NULL, train1_execution, &w);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_create(&train2, NULL, train2_execution, &w);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_create(&train3, NULL, train3_execution, &w);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_create(&train4, NULL, train4_execution, &w);
    if(failure)
        exit(EXIT_FAILURE);

    w.show();
    return a.exec();
}



void* train1_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(2, 1, w);
        sem_wait(&semaphoreL3L4L6); // tenta entrar em L3
        L(3, 1, w);
        L(4, 1, w);
        sem_post(&semaphoreL3L4L6); // libera L4L6L10

        L(1, 1, w);
    }
}

void* train2_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(7, 2, w);
        sem_wait(&semaphoreL5L6L10);     // tenta entrar em L5
        L(5, 2, w);
        L(6, 2, w);

        sem_wait(&semaphoreL3L4L6);     // tenta entrar em L3
        sem_post(&semaphoreL5L6L10); // libera L4L6L10

        L(3, 2, w);                             // percorre L3
        sem_post(&semaphoreL3L4L6);   // libera L3
    }
}

void* train3_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(8, 3, w);
        L(9, 3, w);

        sem_wait(&semaphoreL5L6L10); // tenta entrar em L4L6L10
        L(10, 3, w);
        L(5, 3, w);
        sem_post(&semaphoreL5L6L10); // libera L4L6L10
    }
}

void* train4_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(13, 4, w);
        L(11, 4, w);

        sem_wait(&semaphoreL3L4L6);
        L(4, 4, w);
        sem_wait(&semaphoreL5L6L10);
        L(6, 4, w);
        L(10, 4, w);
        sem_post(&semaphoreL3L4L6);
        L(12, 4, w);
        sem_post(&semaphoreL5L6L10);
    }
}

void L(int path_id, int train, MainWindow *w) {
    for (int i=0; i < 13; i++) {
        if(w->tracks[i] == train)
            w->tracks[i] = 0;          // zera o trilho que o trem estava
    }
    w->tracks[path_id-1] = train;
    w->sleepTime(train);
}
