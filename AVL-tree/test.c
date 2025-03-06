#include <stdio.h>
#include <time.h>
#include "tree.h"

bool testRotateLeft(void) {
    bool errorCode = true;
    Dictionary* dictionary = NULL;

    const char* keys[] = { "i", "e", "d", "f", "y" };
    const char* values[] = { "val1", "val2", "val3", "val4", "val5" };
    /*
         (e)(1)                   (e)(2)                               (i)(1)
        /    \                   /    \             rotateLeft        /    \
     (a)(0)  (i)(-1)   --->   (a)(0)   (i)(0)      ----------->     (e)(0)  (y)(0)
             /                         /   \                       /    \
          (f)(0)                    (f)(0)  (y)(0)               (a)(0)  (f)(0)
    */
    for (int i = 0; i < 5; ++i) {
        dictionary = insert(&dictionary, keys[i], values[i], &errorCode);
    }

    if (!(getBalance(dictionary) == -1 && getBalance(getRightChild(dictionary)) == 0 && getBalance(getLeftChild(dictionary)) == 0
        && getBalance(getLeftChild(getLeftChild(dictionary))) == 0 && getBalance(getRightChild(getLeftChild(dictionary))) == 0)) {
        errorCode = false;
    }

    freeTree(&dictionary);
    return errorCode;
}

bool testRotateRight(void) {
    bool errorCode = true;
    Dictionary* dictionary = NULL;

    const char* keys[] = { "4", "2", "5", "3", "1" };
    const char* values[] = { "val1", "val2", "val3", "val4", "val5" };
    /*
             (4)(-1)                 (4)(-2)                                (2)(1)
            /   \                   /    \              rotateRight        /    \
         (2)(1)  (5)(0)   --->    (2)(0)    (5)(0)      ---------->      (1)(0)  (4)(0)
           \                     /    \                                         /    \
            (3)(0)            (1)(0)  (3)(0)                                 (3)(0)  (5)(0)
    */
    for (int i = 0; i < 5; ++i) {
        dictionary = insert(&dictionary, keys[i], values[i], &errorCode);
    }

    if (!(getBalance(dictionary) == 1 && getBalance(getLeftChild(dictionary)) == 0 && getBalance(getRightChild(dictionary)) == 0
        && getBalance(getRightChild(getRightChild(dictionary))) == 0
        && getBalance(getLeftChild(getRightChild(dictionary))) == 0)) {
        errorCode = false;
    }

    freeTree(&dictionary);
    return errorCode;
}

bool testBigRotateLeft(void) {
    bool errorCode = true;
    Dictionary* dictionary = NULL;

    const char* keys[] = { "c", "e", "d" };
    const char* values[] = { "val1", "val2", "val3" };
    /*
          ñ(2)                       d(0)
            \                       /   \
            e(-1)      --->       c(0)   e(0)
            /
          d(0)
    */
    for (int i = 0; i < 3; ++i) {
        dictionary = insert(&dictionary, keys[i], values[i], &errorCode);
    }

    if (!(getBalance(dictionary) == 0 && getBalance(getLeftChild(dictionary)) == 0 && getBalance(getRightChild(dictionary)) == 0)) {
        errorCode = false;
    }

    freeTree(&dictionary);
    return errorCode;
}

bool testBigRotateRight(void) {
    bool errorCode = true;
    Dictionary* dictionary = NULL;

    const char* keys[] = { "t", "h", "i" };
    const char* values[] = { "val1", "val2", "val3" };
    /*
             t(-2)                 i(0)
            /                     /   \
           h(1)       --->      h(0)  t(0)
            \
             i(0)
    */
    for (int i = 0; i < 3; ++i) {
        dictionary = insert(&dictionary, keys[i], values[i], &errorCode);
    }

    if (!(getBalance(dictionary) == 0 && getBalance(getLeftChild(dictionary)) == 0 && getBalance(getRightChild(dictionary)) == 0)) {
        errorCode = false;
    }

    freeTree(&dictionary);
    return errorCode;
}

bool testRandomInsertions(void) {
    bool errorCode = true;
    Dictionary* dictionary = NULL;
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < 1000000; ++i) {
        char* key = (char)('a' + (rand() % 26));
        char* value = (char)('a' + (rand() % 26));

        dictionary = insert(&dictionary, (const char*)&key, (const char*)&value, &errorCode);

        Dictionary* found = search(&dictionary, (const char*)&key);

        if (found == NULL || getBalance(found) < -1 || getBalance(found) > 1) {
            errorCode = false;
        }
    }

    freeTree(&dictionary);
    return errorCode;
}

bool testOtherFunctions(void) {
    bool errorCode = true;
    Dictionary* dictionary = NULL;

    const char* keys[] = { "z", "n", "k", "m", "a" };
    const char* values[] = { "val1", "val2", "val3", "val4", "val5" };

    for (int i = 0; i < 5; ++i) {
        dictionary = insert(&dictionary, keys[i], values[i], &errorCode);
    }

    if (!search(&dictionary, "m")) {
        errorCode = false;
    }
    deleteElement(&dictionary, "m", &errorCode);

    if (search(&dictionary, "m")) {
        errorCode = false;
    }

    freeTree(&dictionary);
    return errorCode;
}

bool test(void) {
    if (!testRotateLeft() || !testRotateRight()) {
        return false;
    }

    if (!testBigRotateLeft() || !testBigRotateRight()) {
        return false;
    }

    if (!testOtherFunctions()) {
        return false;
    }

    if (!testRandomInsertions()) {
        return false;
    }

    return true;
}
