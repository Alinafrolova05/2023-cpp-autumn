#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool MismatchedLetters(char string[],char substring[], int j, int indexSubstring) {
    return string[j] == substring[indexSubstring];
}

void NumberOfOccurrences(char string[], char substring[], int* countSubstrings)
{
    int countSubstringsVoid = 0;
    int indexSubstring = 0;
    int checkIdenticalLetters = 0;

    for (int j = 0; string[j] != '\0'; ++j) {

        if (!MismatchedLetters(string, substring, j, indexSubstring)) {
            checkIdenticalLetters = 0;
            indexSubstring = 0;
            continue;
        }

        checkIdenticalLetters++;
        indexSubstring++;

        if (checkIdenticalLetters == strlen(substring) - 1) {
            countSubstringsVoid++;
            checkIdenticalLetters = 0;
            indexSubstring = 0;
        }
    }

    *countSubstrings = countSubstringsVoid;
}

int main(void)
{
    char string[100] = "x";
    char substring[100] = "w";
    int countSubstrings = 1;

    printf("Enter a string S with less than 100 characters: ");
    fgets(string, 100, stdin);
    printf("Enter a substring S1 with less than 100 characters: ");
    fgets(substring, 100, stdin);

    NumberOfOccurrences(string, substring, &countSubstrings);
    printf("Number of occurrences of S1 in S as substrings: %d", countSubstrings);
}
