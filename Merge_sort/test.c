#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "mergeSorting.h"
#include "inputOutput.h"
#include "numbers.h"
#include "test.h"

bool test(void) {
    bool errorCode = true;
    List* phoneList = NULL;

    Number* phone1 = createNumber();
    strcpy(getName(phone1), "Dmitry");
    strcpy(getNumber(phone1), "12345");
    push(&phoneList, phone1);

    Number* phone2 = createNumber();
    strcpy(getName(phone2), "Sergey");
    strcpy(getNumber(phone2), "67891");
    push(&phoneList, phone2);

    Number* phone3 = createNumber();
    strcpy(getName(phone3), "Anna");
    strcpy(getNumber(phone3), "01112");
    push(&phoneList, phone3);

    List* correctList = NULL;
    Number* correct1 = createNumber();
    strcpy(getName(correct1), "Sergey");
    strcpy(getNumber(correct1), "67891");
    push(&correctList, correct1);

    Number* correct2 = createNumber();
    strcpy(getName(correct2), "Dmitry");
    strcpy(getNumber(correct2), "12345");
    push(&correctList, correct2);

    Number* correct3 = createNumber();
    strcpy(getName(correct3), "Anna");
    strcpy(getNumber(correct3), "01112");
    push(&correctList, correct3);

    mergeSort(&phoneList, SORT_BY_NAME);

    List* currentPhone = phoneList;
    List* currentCorrect = correctList;

    while (currentPhone != NULL && currentCorrect != NULL) {
        if (strcmp(getName(getNumberOfList(currentPhone)), getName(getNumberOfList(currentCorrect))) != 0 ||
            strcmp(getNumber(getNumberOfList(currentPhone)), getNumber(getNumberOfList(currentCorrect))) != 0) {
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
