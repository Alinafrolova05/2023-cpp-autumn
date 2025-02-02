#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include "tree.h"

struct Node {
    const char* key;
    const char* value;
    int balance;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
};

bool testRotateLeft(void) {
    bool errorCode = true;
    Node* root = NULL;

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
        root = insert(&root, keys[i], values[i], &errorCode);
    }

    if (!(root->balance == -1 && root->right->balance == 0 && root->left->balance == 0
        && root->left->left->balance == 0 && root->left->right->balance == 0)) {
        errorCode = false;
    }

    freeTree(&root);
    return errorCode;
}

bool testRotateRight(void) {
    bool errorCode = true;
    Node* root = NULL;

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
        root = insert(&root, keys[i], values[i], &errorCode);
    }

    if (!(root->balance == 1 && root->left->balance == 0 && root->right->balance == 0
        && root->right->right->balance == 0 && root->right->left->balance == 0)) {
        errorCode = false;
    }

    freeTree(&root);
    return errorCode;
}

bool testBigRotateLeft(void) {
    bool errorCode = true;
    Node* root = NULL;

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
        root = insert(&root, keys[i], values[i], &errorCode);
    }

    if (!(root->balance == 0 && root->right->balance == 0 && root->left->balance == 0)) {
        errorCode = false;
    }

    freeTree(&root);
    return errorCode;
}

bool testBigRotateRight(void) {
    bool errorCode = true;
    Node* root = NULL;

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
        root = insert(&root, keys[i], values[i], &errorCode);
    }

    if (!(root->balance == 0 && root->right->balance == 0 && root->left->balance == 0)) {
        errorCode = false;
    }

    freeTree(&root);
    return errorCode;
}

bool testRandomInsertions(void) {
    bool errorCode = true;
    Node* root = NULL;
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < 1000000; ++i) {
        char* key = (char)('a' + (rand() % 26));
        char* value = (char)('a' + (rand() % 26));

        root = insert(&root, (const char*)&key, (const char*)&value, &errorCode);

        Node* node = search(&root, (const char*)&key);

        if (node == NULL || node->balance < -1 || node->balance > 1) {
            errorCode = false;
        }
    }

    freeTree(&root);
    return errorCode;
}

bool testOtherFunctions(void) {
    bool errorCode = true;
    Node* root = NULL;

    const char* keys[] = { "z", "n", "k", "m", "a" };
    const char* values[] = { "val1", "val2", "val3", "val4", "val5" };

    for (int i = 0; i < 5; ++i) {
        root = insert(&root, keys[i], values[i], &errorCode);
    }

    if (!search(&root, "m")) {
        errorCode = false;
    }
    deleteElement(&root, "m", &errorCode);

    if (search(&root, "m")) {
        errorCode = false;
    }

    freeTree(&root);
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
}
