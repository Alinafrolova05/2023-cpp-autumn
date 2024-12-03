#include "functions.h"

int hash(char* key) {
    int hash_index = 0;
    while (key[hash_index] != '\0') {
        hash_index++;
    }
    return hash_index;
}