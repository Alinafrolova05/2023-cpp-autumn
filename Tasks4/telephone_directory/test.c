#include <string.h>
#include "test.h"
#include "directory.h"

bool test(void) {
    PhoneBook* entry = createPhoneBook();
    int size = 0;
    bool errorCode = true;

    setName(entry, size, "rtrt");
    setNumber(entry, size, "1111");
    size++;

    char nameToFind[NAME_LENGTH] = "rtrt";
    bool found = find(entry, nameToFind, size);
    free(entry);
    return found;
}
