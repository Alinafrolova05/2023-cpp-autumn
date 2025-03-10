#include <string.h>
#include "test.h"
#include "directory.h"

bool test(FILE* file) {
    bool errorCode = true;
    char buffer[50] = { 0 };
    char name[50] = "rtrt";
    find(file, name, buffer, &errorCode);
    if (!errorCode) {
        return false;
    }
    return true;
}
