#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

bool test(FILE* file1, FILE* file2) {
    if (file1 == NULL) {
        printf("Ошибка! ");
        return -1;
    }
    if (file2 == NULL) {
        printf("Ошибка! ");
        fclose(file1);
        return -1;
    }
}
void fillArray(FILE* file1, char str[]) {
    while (!feof(file1)) {
        char* res = fgets(str, 100, file1);
        if (res = NULL) {
            break;
        }
    }
}

void text(char str[], char buffer[]) {
    int indexBuffer = 0;
    int k = 0;
    while (str[k] != '\0') {
        if (str[k] == '"') {
            k++;
            while (str[k] != '"') {
                buffer[indexBuffer] = str[k];
                indexBuffer++;
                k++;
            }
            buffer[indexBuffer] = ' ';
            indexBuffer++;
        }
        k++;
    }
}

void print(char buffer[], FILE* file2) {
    for (int i = 0; buffer[i] != '\0'; ++i) {
        fprintf(file2, "%s", &buffer[i]);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    FILE* file1 = fopen("input.txt", "r");
    FILE* file2 = fopen("output.txt", "w");

    test(file1, file2);
    char str[100] = { 0 };
    fillArray(file1, str);

    int buffer[100] = { 0 };
    text(str, buffer);
    print(buffer, file2);

    fclose(file1);
    fclose(file2);
    return 0;
}
