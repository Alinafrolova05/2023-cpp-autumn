#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    char string[100] = { 0 };
    printf("Введите строу менее 100 символов: ");
    fgets(string, 100, stdin);
    int count = 0;
    int countSubstring = 0;
    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ') {
            countSubstring++;
            continue;
        }
        if (string[i] == string[strlen(string) - i]) {
            count++;
        }
    }
    if (count == strlen(string) - countSubstring) {
        printf("\nСтрока является палиндромом");
    }
    else {
        printf("Строка не являтся палиндромом");
    }

    return 0;
}

