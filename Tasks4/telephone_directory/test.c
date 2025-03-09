#include <string.h>
#include "test.h"
#include "directory.h"

bool test(FILE* file) {
    char buffer[50] = { 0 };
    char name[50] = "rtrt";
    find(file, name, buffer);
    for (int i = 0; i < strlen("rtrt"); ++i) {
        if (buffer[i] != name[i]) {
            return false;
        }
    }
    return true;
}
