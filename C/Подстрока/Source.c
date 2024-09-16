#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void NumberOfOccurrences(char str[], char sub[])
{
    int countsub = 0;
    for (int i = 0; sub[i] != '\0'; ++i) {
        countsub++;
    }
    int count = 0;
    int isub = 0;
    int check = 0;
    for (int jstr = 0; str[jstr] != '\0'; ++jstr) {
        if (str[jstr] == sub[isub]) {
            check++;
            isub++;
        } else {
            check = 0;
            isub = 0;
        }
        if (check == countsub - 1) {
            count++;
            check = 0;
            isub = 0;
        }
    }
    printf("Number of occurrences of S1 in S as substrings: %d", count);
}

int main(void)
{
    char str[100] = "x";
    char sub[100] = "w";
    printf("Enter a string S with less than 100 characters: ");
    fgets(str, 100, stdin);
    printf("Enter a substring S1 with less than 100 characters: ");
    fgets(sub, 100, stdin);
    NumberOfOccurrences(str, sub);
}
