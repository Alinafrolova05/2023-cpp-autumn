#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

#define INT_MAX 100

void push(Graphs** element1, int number, int weight) {
    Graphs* element = (Graphs*)calloc(1, sizeof(Graphs));
    element->number = number;
    element->weight = weight;
    element->next = *element1;
    *element1 = element;
}

void pop(Graphs** element1) {
    Graphs* tmp = *element1;
    *element1 = (*element1)->next;
    free(tmp);
}

void listOf(FILE* file, Graphs* table, int n) {
    char buffer[256] = { 0 };
    while (fgets(buffer, sizeof(buffer), file)) {
        if (buffer[0] == '/') break;
        int from = 0;
        int to = 0;
        int weight = 0;
        sscanf(buffer, "%d %d %d", &from, &to, &weight);
        push(&table[from], to, weight);
        push(&table[to], from, weight);
    }
}

void dijkstra(Graphs* table, int start, int n, int* distances) {
    int* visited = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        distances[i] = INT_MAX;
    }
    distances[start] = 0;

    for (int i = 0; i < n; i++) {
        int minDistance = INT_MAX;
        int current = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];
                current = j;
            }
        }

        if (current == -1) break;

        visited[current] = 1;

        for (Graphs* edge = &table[current]; edge != NULL; edge = edge->next) {
            int newDistance = distances[current] + edge->weight;
            if (newDistance < distances[edge->number]) {
                distances[edge->number] = newDistance;
            }
        }
    }

    free(visited);
}

void countingSort(int size, int* array) {
    int max = 0;
    for (int i = 0; i < size; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    int* anotherArray = (int*)calloc(max, sizeof(int));
    for (int i = 0; i < size; ++i) {
        anotherArray[array[i]]++;
    }
    int k = 0;
    for (int i = 0; i < max; ++i) {
        for (int j = 0; j < anotherArray[i]; ++j) {
            array[k] = i;
            k++;
        }
    }
}

bool testSort() {
    int array[] = {9, 4, 6, 2, 7};
    int size = 5;
    countingSort(size, array);
    int check = 0;
    for (int i = 1; i < size; ++i) {
        if (array[i] < array[i - 1]) {
            check = 1;
            break;
        }
    }
    return check == 0;
}

void algorithm(Graphs* table, int n, int* capitals, Graphs* state, int k) {
    int visited[128] = { 0 };
    for (int i = 0; i < k; ++i) {
        visited[i] = capitals[i];
    }
    int sizeOfVisited = k;

    int* distances = (int*)malloc(n * sizeof(int));

    for (int i = 0; sizeOfVisited < n; ++i) {
        dijkstra(table, capitals[i % k], n, distances);
        countingSort(n, distances);
        for (int t = 0; t < n; ++t) {
            int check = 0;
            for (int j = 0; j < sizeOfVisited; ++j) {
                if (distances[t] == visited[j]) {
                    check++;
                    break;
                }
            }
            if (check == 0) {
                push(&state[i % k], t, 0);
                visited[sizeOfVisited] = t;
                sizeOfVisited++;
                break;
            }
        }
    }

    free(distances);
}

void print(Graphs* state, int k) {
    for (int i = 0; i < k; ++i) {
        while (state[i].next != NULL) {
            printf(" %d", state[i].number);
            state[i] = *(state[i]).next;
        }
        printf("\n");
    }
}
