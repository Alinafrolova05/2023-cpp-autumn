#ifndef TREE
#include <stdbool.h>
typedef struct Graphs {
    int number;
    int weight;
    struct Graphs* next;
} Graphs;

void push(Graphs** element1, int number, int weight);
void pop(Graphs** element1);
void listOf(FILE* file, Graphs* table, int n);
void dijkstra(Graphs* table, int start, int n, int* distances, int* previous);
void algorithm(Graphs* table, int n, int* capitals, Graphs* state, int k);
void countingSort(int size, int* array);
bool testSort();
void print(Graphs* state, int k);
#endif