#include <stdio.h>
#include "test.h"
#include "sorting.h"

bool test(void) {
    bool errorCode = true;
    char str[20] = "(2+2)/9";
    char correct[20] = "22+9/";

    char* array = solution(str, &errorCode);

    char isCorrect[256] = { 0 };
    for (int i = 0; array[i]!= '\0'; ++i) {
        isCorrect[i] = array[i];
    }
    free(array);
   
    return strcmp(correct, isCorrect) == 0 && errorCode == true;
}
