#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    FILE* file1 = fopen("input.txt", "r");
    FILE* file2 = fopen("output.txt", "w");
    
    if (file1 == NULL || file2 == NULL) {
        printf("Ошибка! ");
        return -1;
    }
    char str[100] = { 0 };
    int i = 0;
    while (!feof(file1)) {
        char *res = fgets(str, 100, file1);
        if (res = NULL) {
            break;
        }
    }

    int buffer[100] = { 0 };
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
    for (int i = 0; buffer[i] != '\0'; ++i) {
        fprintf(file2, "%s", &buffer[i]);
    }

    fclose(file1);
    fclose(file2);
    return 0;
}
