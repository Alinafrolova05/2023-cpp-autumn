#include <stdio.h>
#include <malloc.h>

typedef struct Element {
    int value;
    struct Element* next;
}Element;

Element* createNode(int number) {
    Element* newNode = (Element*)malloc(sizeof(Element));
    newNode->value = number;
    newNode->next = NULL;
    return newNode;
}

int count(int numberOfWarriors, int warriorBeingKilled) {
    Element* head = createNode(1);
    Element* current = head;

    for (int i = 2; i <= numberOfWarriors; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    current->next = head;

    Element* currentWarrior = head;

    while (currentWarrior->next != currentWarrior) {
        for (int count = 1; count < warriorBeingKilled - 1; count++) {
            currentWarrior = currentWarrior->next;
        }
        Element* toDelete = currentWarrior->next;
        currentWarrior->next = toDelete->next;
        free(toDelete);
        currentWarrior = currentWarrior->next;
    }

    int lastSurvivor = currentWarrior->value;
    free(currentWarrior);
    return lastSurvivor;
}
