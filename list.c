#include "list.h"

int hash(char* key) {
    int hashIndex = 0;
    while (key[hashIndex] != '\0') {
        hashIndex++;
    }
    return hashIndex;
}

int getValueHash(char* key) {
    return hash(key);
}
