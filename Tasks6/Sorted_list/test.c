#include <stdio.h>
#include "list.h"

bool test(void) {
    bool errorCode = true;
    Element* element = NULL;

    addElement(&element, 5, &errorCode);
    addElement(&element, 6, &errorCode);

    if (!(getElementValue(element) == 5 && getElementValue(elementNext(element)) == 6)) {
        errorCode = false;
    }

    deleteElement(&element, 5);
    deleteElement(&element, 6);

    return element == NULL && errorCode == true;
}
