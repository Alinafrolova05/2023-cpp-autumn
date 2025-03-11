#define _CRT_SECURE_NO_WARNINGS

#include "directory.h"
#include "test.h"

void printSolution(char* charFile, PhoneBook* entry, int* size) {
    bool errorCode = true;
    loadFromFile(charFile, entry, size, &errorCode);
    if (!errorCode) {
        printf("Error loading phonebook from file!\n");
        return;
    }

    int option = -1;
    printf("\nChoose an option: ");
    scanf("%d", &option);

    while (option != 0) {
        if (option == 1) {
            if (*size < MAX_ENTRIES) {
                getEntryFromUser(entry, *size);
                (*size)++;
            }
            else {
                printf("Phonebook is full!\n");
            }
        }
        else if (option == 2) {
            printAllEntries(entry, *size);
        }
        else if (option == 3) {
            char name[NAME_LENGTH] = "";
            printf("\nInput name: ");
            scanf("%s", name);
            if (find(entry, name, *size)) {
                printf("Found: %s\n", name);
            }
            else {
                printf("This name was not found.\n");
            }
        }
        else if (option == 4) {
            char number[NUMBER_LENGTH] = { 0 };
            printf("\nInput number: ");
            scanf("%s", number);
            if (find(entry, number, *size)) {
                printf("Found: %s\n", number);
            }
            else {
                printf("This number was not found.\n");
            }
        }
        else if (option == 5) {
            saveToFile(charFile, entry, *size, &errorCode);
            if (!errorCode) {
                printf("Error saving phonebook to file!\n");
                break;
            }
        }
        else {
            printf("Input Error!!!!!\n");
        }
        printf("\nNext option: ");
        scanf("%d", &option);
    }
}
int main(void) {
    if (!test()) {
        printf("Error!!!");
        return -1;
    }
    printf("Specify option number:\n");
    printf("0 - exit");
    printf("\n1 - add an entry(name and phone number)");
    printf("\n2 - print all existing records");
    printf("\n3 - find a phone by name");
    printf("\n4 - find a name by phone");
    printf("\n5 - save current data to file");

    int size = 0;
    PhoneBook* entry = createPhoneBook();
    printSolution("text.txt", entry, &size);

    free(entry);
    return 0;
}
