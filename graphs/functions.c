#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
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
        sscanf_s(buffer, "%d %d %d", &from, &to, &weight);
        push(&table[from], to, weight);
        push(&table[to], from, weight);
    }
}

void dijkstra(Graphs* table, int start, int n, int* distances, int* previous) {
    int* visited = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        distances[i] = INT_MAX;
        previous[i] = -1;
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
                previous[edge->number] = current;
            }
        }
    }

    free(visited);
}

void algorithm(Graphs* table, int n, int* capitals, Graphs* state, int k) {
    int* distances = (int*)malloc(n * sizeof(int));
    int* previous = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < k; i++) {
        dijkstra(table, capitals[i], n, distances, previous);
        printf("Distances from capital %d:\n", capitals[i]);
        for (int j = 0; j < n; j++) {
            if (distances[j] != INT_MAX) {
                printf("City %d: %d\n", j, distances[j]);

            }
            else {
                printf("City %d: Unreachable\n", j);
            }
        }
    }
    free(distances);
    free(previous);
}