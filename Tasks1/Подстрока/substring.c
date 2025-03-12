#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isMismatched(char element1, char element2) {
    return element1 == element2;
}

int numberOfOccurrences(char string[], char substring[]) {
    int matchedSubstrings = 0;
    int indexSubstring = 0;

    for (int j = 0; string[j] != '\0'; ++j) {

        if (!isMismatched(string[j], substring[indexSubstring])) {
            indexSubstring = 0;
            continue;
        }

        indexSubstring++;

        if (indexSubstring == strlen(substring) - 1) {
            matchedSubstrings++;
            indexSubstring = 0;
        }
    }

    return matchedSubstrings;
}

int main(void) {
    const char string[100] = "";
    const char substring[100] = "";

    printf("Enter a string S with less than 100 characters: ");
    fgets(string, 100, stdin);
    printf("Enter a substring S1 with less than 100 characters: ");
    fgets(substring, 100, stdin);

    numberOfOccurrences(string, substring);
    printf("Number of occurrences of S1 in S as substrings: %d", numberOfOccurrences(string, substring));
}
