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

pthread_mutex_t mutex_L4L6L10;

//pthread_mutex_t mutex_train14;   // mutex for train 1 and 4 intersection
//pthread_mutex_t mutex_train24;   // mutex for train 2 and 4 intersection
//pthread_mutex_t mutex_train34;   // mutex for train 3 and 4 intersection

// TRAIN VELOCITY ARRAY
int train_velocity[4] = {8, 4, 2, 1};

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
    failure = pthread_mutex_init(&mutex_L4L6L10, NULL);
    if(failure)
        exit(EXIT_FAILURE);
//    failure = pthread_mutex_init(&mutex_train14, NULL);
//    if(failure)
//        exit(EXIT_FAILURE);
//    failure = pthread_mutex_init(&mutex_train24, NULL);
//    if(failure)
//        exit(EXIT_FAILURE);
//    failure = pthread_mutex_init(&mutex_train34, NULL);
//    if(failure)
//        exit(EXIT_FAILURE);

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
        w->resetColorLine(2);
        L(3, 1, w);

        pthread_mutex_lock(&mutex_L4L6L10);     // tenta entrar em L4 L6 L10

        pthread_mutex_unlock(&mutex_train12); // libera L3
        w->resetColorLine(3);
        L(4, 1, w);
        w->resetColorLine(4);

        pthread_mutex_unlock(&mutex_L4L6L10);   // libera L4 L6 L10

        L(1, 1, w);
        w->resetColorLine(1);
    }
}

void* train2_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(7, 2, w);
        pthread_mutex_lock(&mutex_train23);     // tenta entrar em L5
        w->resetColorLine(7);
        L(5, 2, w);

        pthread_mutex_lock(&mutex_L4L6L10);     // tenta entrar em L4 L6 L10

        pthread_mutex_unlock(&mutex_train23);   // libera L5
        w->resetColorLine(5);
        L(6, 2, w);
        pthread_mutex_lock(&mutex_train12);     // tenta entrar em L3

        pthread_mutex_unlock(&mutex_L4L6L10);   // libera L4 L6 L10

        w->resetColorLine(6);                   // reseta cor de L6
        L(3, 2, w);                             // percorre L3
        w->resetColorLine(3);                   // reseta cor de L3
        pthread_mutex_unlock(&mutex_train12);   // libera L3
    }
}

void* train3_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(8, 3, w);
        w->resetColorLine(8);
        L(9, 3, w);
        pthread_mutex_lock(&mutex_L4L6L10);     // tenta entrar em L4 L6 L10

        w->resetColorLine(9);                   // reseta cor L9
        L(10, 3, w);                            // percorre L10

        pthread_mutex_lock(&mutex_train23);     // tenta entrar em L5

        pthread_mutex_unlock(&mutex_L4L6L10);   // libera L4 L6 L10

        w->resetColorLine(10);
        L(5, 3, w);
        w->resetColorLine(5);
        pthread_mutex_unlock(&mutex_train23);   // libera L5
    }
}

void* train4_execution(void *w_old){
    MainWindow *w = (MainWindow*)w_old;
    while(true) {
        L(13, 4, w);
        w->resetColorLine(13);
        L(11, 4, w);
        pthread_mutex_lock(&mutex_L4L6L10);     // tenta entrar em L4 L6 L10


        w->resetColorLine(11);
        L(4, 4, w);
        w->resetColorLine(4);
        L(6, 4, w);
        w->resetColorLine(6);
        L(10, 4, w);
        w->resetColorLine(10);

        pthread_mutex_unlock(&mutex_L4L6L10);   // libera L4 L6 L10
        L(12, 4, w);

        w->resetColorLine(12);
    }
}

void L(int path_id, int train, MainWindow *w) {
    w->setColorLine(path_id, train);
    sleep(train_velocity[train - 1]); // the array index starts with 0
}
