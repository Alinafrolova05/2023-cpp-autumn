#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>

void palindrome(char *string, int *pointerCount, int *pointerCountSubstrings) {
    int countSubstrings = 0;
    int count = 0;
    int index = 0;
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ') {
            countSubstrings++;
            continue;
        }
        while (string[strlen(string) - index - 2] == ' ') {
            index++;
        }
        if (string[i] == string[strlen(string) - index - 2]) {
            count++;
            index++;
        }
    }
    *pointerCount = count;
    *pointerCountSubstrings = countSubstrings;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char string[100] = { 0 };
    printf("Введите не более 100 символов: ");
    fgets(string, 100, stdin);
    
    int countSubstringsP = 0;
    int countP = 0;

    palindrome(string, &countP, &countSubstringsP);

    if (countP == strlen(string) - 1 - countSubstringsP) {
        printf("Строка является палидромом. ");
    } else {
        printf("Строка не является палидромом. ");
    }
    return 0;
}
