#include "test.h"
#include "solution.h"

bool test(void) {
    bool errorCode = true;
    Element* element = solution(3);
    if (getValue(element) != 1 || getValue(getNext(element)) != 2) {
        errorCode = false;
    }
    deleteLine(&element);
    return errorCode;
}
