#include "functions.h"
void enqueue(int* array, int* finish, int value) {
    array[*finish] = value;
    (*finish)++;
}
void dequeue(int* array, int* start, int* finish) {
    if (*start < *finish) {
        (*start)++;
    }
    else {
        printf("Error.\n");
    }
}
void print(int* array, int start, int finish) {
    for (int i = start; i < finish; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}