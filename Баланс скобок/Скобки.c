#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void Check(char str[]) {
    int count = 0;
    int countskobka1 = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '(') {
            countskobka1++;
        }
        if (str[i] == ')') {
            if (countskobka1 == 0) {
                printf(" ) is wrong");
                count++;
            } else {
                countskobka1--;
            }
        }
    }
    for (int i = 0; i < countskobka1; ++i) {
        printf(" ( is wrong");
    }
    if (countskobka1 == 0 && count == 0) {
        printf("Nothing is wrong");
    }
}

int main(void) {
    printf("Enter less than 100 characters: ");
    char str[100] = "x";
    fgets(str, 99, stdin);
    Check(str);
}
