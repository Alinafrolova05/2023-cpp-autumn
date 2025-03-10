#include <string.h>
#include "mergeSorting.h"
#include "inputOutput.h"
#include "sort.h"
#include "test.h"

bool testSortByName(void) {
    List* phoneList = NULL;

    Number* phone1 = createNumber();
    strcpy(getName(phone1), "Dmitry");
    strcpy(getNumber(phone1), "12345");
    phoneList = createNode(phone1);

    Number* phone2 = createNumber();
    strcpy(getName(phone2), "Sergey");
    strcpy(getNumber(phone2), "67891");
    phoneList->next = createNode(phone2);

    Number* phone3 = createNumber();
    strcpy(getName(phone3), "Anna");
    strcpy(getNumber(phone3), "01112");
    phoneList->next->next = createNode(phone3);

    List* correctList = NULL;
    Number* correct1 = createNumber();
    strcpy(getName(correct1), "Anna");
    strcpy(getNumber(correct1), "01112");
    correctList = createNode(correct1);

    Number* correct2 = createNumber();
    strcpy(getName(correct2), "Dmitry");
    strcpy(getNumber(correct2), "12345");
    correctList->next = createNode(correct2);

    Number* correct3 = createNumber();
    strcpy(getName(correct3), "Sergey");
    strcpy(getNumber(correct3), "67891");
    correctList->next->next = createNode(correct3);

    mergeSort(&phoneList, SORT_BY_NAME);

    List* currentPhone = phoneList;
    List* currentCorrect = correctList;

    while (currentPhone != NULL && currentCorrect != NULL) {
        if (strcmp(getName(currentPhone->element), getName(currentCorrect->element)) != 0 ||
            strcmp(getNumber(currentPhone->element), getNumber(currentCorrect->element)) != 0) {
            freeList(&phoneList);
            freeList(&correctList);
            return false;
        }
        currentPhone = getNextList(currentPhone);
        currentCorrect = getNextList(currentCorrect);
    }

    freeList(&phoneList);
    freeList(&correctList);
    return true;
}

bool testSortByNumber(void) {
    List* phoneList = NULL;

    Number* phone1 = createNumber();
    strcpy(getName(phone1), "Sergey");
    strcpy(getNumber(phone1), "67891");
    phoneList = createNode(phone1);

    Number* phone2 = createNumber();
    strcpy(getName(phone2), "Anna");
    strcpy(getNumber(phone2), "01112");
    phoneList->next = createNode(phone2);

    Number* phone3 = createNumber();
    strcpy(getName(phone3), "Dmitry");
    strcpy(getNumber(phone3), "12345");
    phoneList->next->next = createNode(phone3);

    List* correctList = NULL;
    Number* correct1 = createNumber();
    strcpy(getName(correct1), "Anna");
    strcpy(getNumber(correct1), "01112");
    correctList = createNode(correct1);

    Number* correct2 = createNumber();
    strcpy(getName(correct2), "Dmitry");
    strcpy(getNumber(correct2), "12345");
    correctList->next = createNode(correct2);

    Number* correct3 = createNumber();
    strcpy(getName(correct3), "Sergey");
    strcpy(getNumber(correct3), "67891");
    correctList->next->next = createNode(correct3);

    mergeSort(&phoneList, SORT_BY_NUMBER);

    List* currentPhone = phoneList;
    List* currentCorrect = correctList;

    while (currentPhone != NULL && currentCorrect != NULL) {
        if (strcmp(getName(currentPhone->element), getName(currentCorrect->element)) != 0 ||
            strcmp(getNumber(currentPhone->element), getNumber(currentCorrect->element)) != 0) {
            freeList(&phoneList);
            freeList(&correctList);
            return false;
        }
        currentPhone = getNextList(currentPhone);
        currentCorrect = getNextList(currentCorrect);
    }

    freeList(&phoneList);
    freeList(&correctList);
    return true;
}
