#include "hash.h"
#include "table.h"

int hash(const char* key) {
    int hashIndex = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        int number = (int)key[i];
        if (key[i] == 'g' || key[i] == 'j' || key[i] == 'p' || key[i] == 'q' || key[i] == 'y') {
            number *= 23;
        }        
        if (i % 2 == 0) {
            number /= 3;
        }
        if (i % 3 == 0) {
            number %= 11;
        }
        hashIndex += number;
    }
    return hashIndex % getSizeOfTable();
}

int getValueHash(const char* key) {
    return hash(key);
}
