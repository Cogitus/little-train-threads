#include "mainwindow.h"

#include <QApplication>

#include <iostream>
#include <unistd.h>     // for sleep()
#include <algorithm>    // for fill_n()
#include <pthread.h>

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
pthread_mutex_t mutex_train14;   // mutex for train 1 and 4 intersection
pthread_mutex_t mutex_train24;   // mutex for train 2 and 4 intersection
pthread_mutex_t mutex_train34;   // mutex for train 3 and 4 intersection

// TRAIN VELOCITY ARRAY
//int train_velocity[13] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int train_velocity[4] = {1, 1, 1, 1};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    int failure;    // the flag for the pthread functions return codes
    // TRAIN THREADS DEFINITIONS
    pthread_t train1, train2, train3, train4;

    // initializing the mutexes
    failure = pthread_mutex_init(&mutex_train12, NULL);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_mutex_init(&mutex_train23, NULL);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_mutex_init(&mutex_train14, NULL);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_mutex_init(&mutex_train24, NULL);
    if(failure)
        exit(EXIT_FAILURE);
    failure = pthread_mutex_init(&mutex_train34, NULL);
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
        pthread_mutex_lock(&mutex_train12); // tenta entrar em L3
        L(3, 1, w);
        pthread_mutex_unlock(&mutex_train12); // libera L3
        pthread_mutex_lock(&mutex_train14); // tenta entrar em L4
        L(4, 1, w);
        pthread_mutex_unlock(&mutex_train14);
        L(1, 1, w);
    }
}

void* train2_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(7, 2, w);
        pthread_mutex_lock(&mutex_train23);
        L(5, 2, w);
        pthread_mutex_unlock(&mutex_train23);
        pthread_mutex_lock(&mutex_train24);
        L(6, 2, w);
        pthread_mutex_unlock(&mutex_train24);
        pthread_mutex_lock(&mutex_train12);
        L(3, 2, w);
        pthread_mutex_unlock(&mutex_train12);
    }
}

void* train3_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(8, 3, w);
        L(9, 3, w);
        pthread_mutex_lock(&mutex_train34);
        L(10, 3, w);
        pthread_mutex_unlock(&mutex_train34);
        pthread_mutex_lock(&mutex_train23);
        L(5, 3, w);
        pthread_mutex_unlock(&mutex_train23);
    }
}

void* train4_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(13, 4, w);
        L(11, 4, w);
        pthread_mutex_lock(&mutex_train14);
        L(4, 4, w);
        pthread_mutex_unlock(&mutex_train14);
        pthread_mutex_lock(&mutex_train24);
        L(6, 4, w);
        pthread_mutex_unlock(&mutex_train24);
        pthread_mutex_lock(&mutex_train34);
        L(10, 4, w);
        pthread_mutex_unlock(&mutex_train34);
        L(12, 4, w);
    }
}

void L(int path_id, int train, MainWindow *w) {
    w->setColorLine(path_id, train);
    //cout << "train " << train << " is now over L" << path_id << endl;
    sleep(train_velocity[train - 1]); // the array index starts with 0
}
