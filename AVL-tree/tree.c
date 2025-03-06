#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "tree.h"

typedef struct Dictionary {
    const char* key;
    const char* value;
    int balance;
    struct Dictionary* parent;
    struct Dictionary* left;
    struct Dictionary* right;
} Dictionary;

const char* getValue(Dictionary* node) {
    return node->value;
}

int getBalance(Dictionary* node) {
    return node->balance;
}

Dictionary* getLeftChild(Dictionary* node) {
    return node->left;
}

Dictionary* getRightChild(Dictionary* node) {
    return node->right;
}

char* myStrdup(const char* str) {
    if (str == NULL) return NULL;
    size_t len = strlen(str) + 1;
    char* copy = (char*)malloc(len);
    if (copy) {
        strcpy(copy, str);
    }
    return copy;
}

void freeTree(Dictionary** root) {
    if (*root == NULL) return;
    freeTree(&((*root)->left));
    freeTree(&((*root)->right));
    free((char*)(*root)->key);
    free((char*)(*root)->value);
    free(*root);
    *root = NULL;
}

Dictionary* rotateLeft(Dictionary* node) {
    if (node == NULL || node->right == NULL) {
        return node;
    }

    Dictionary* b = node->right;
    node->right = b->left;
    b->left = node;

    if (node->left != NULL) {
        node->left->parent = node;
    }
    b->parent = node->parent;
    node->parent = b;

    node->balance -= 2;
    b->balance--;

    return b;
}

Dictionary* rotateRight(Dictionary* node) {
    if (node == NULL || node->left == NULL) {
        return node;
    }

    Dictionary* a = node->left;
    node->left = a->right;
    a->right = node;

    if (node->left != NULL) {
        node->left->parent = node;
    }
    a->parent = node->parent;
    node->parent = a;

    node->balance += 2;
    a->balance++;

    return a;
}

Dictionary* bigRotateLeft(Dictionary* node) {
    if (node == NULL || node->right == NULL || node->right->left == NULL) {
        return node;
    }

    Dictionary* c = node->right->left;
    node->right->left = c->right;
    c->right = node->right;
    node->right = c->left;
    c->left = node;

    if (c->left->right != NULL) {
        c->left->right->parent = c->left;
    }
    if (c->right->left != NULL) {
        c->right->left->parent = c->right;
    }
    c->parent = node->parent;
    c->left->parent = c;
    c->right->parent = c;

    c->left->balance -= 2;
    c->right->balance++;

    return c;
}

Dictionary* bigRotateRight(Dictionary* node) {
    if (node == NULL || node->left == NULL || node->left->right == NULL) {
        return node;
    }

    Dictionary* c = node->left->right;
    node->left->right = c->left;
    c->left = node->left;
    node->left = c->right;
    c->right = node;

    if (c->left->right != NULL) {
        c->left->right->parent = c->left;
    }
    if (c->right->left != NULL) {
        c->right->left->parent = c->right;
    }
    c->parent = node->parent;
    c->left->parent = c;
    c->right->parent = c;

    c->right->balance += 2;
    c->left->balance--;

    return c;
}

Dictionary* balance(Dictionary* node) {
    if (node->balance == -2) {
        if (node->left->balance <= 0) {
            return rotateRight(node);
        }
        return bigRotateRight(node);
    }
    if (node->balance == 2) {
        if (node->right->balance >= 0) {
            return rotateLeft(node);
        }
        return bigRotateLeft(node);
    }
    return node;
}

Dictionary* insert(Dictionary** root, const char* key, const char* value, bool* errorCode) {
    if (*root == NULL) {
        Dictionary* newNode = (Dictionary*)calloc(1, sizeof(Dictionary));
        if (newNode == NULL) {
            *errorCode = false;
            return NULL;
        }
        newNode->key = myStrdup(key);
        if (!*errorCode) {
            free(newNode);
            return NULL;
        }
        newNode->value = myStrdup(value);
        if (!*errorCode) {
            free(newNode);
            return NULL;
        }
        newNode->balance = 0;
        newNode->parent = *root;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
        return *root;
    }
    if (strcmp(key, (*root)->key) < 0) {
        (*root)->balance--;
        (*root)->left = insert(&(*root)->left, key, value, errorCode);
        if (!*errorCode) {
            freeTree(root);
            return NULL;
        }
    } else if (strcmp(key, (*root)->key) == 0) {
        return *root;
    } else {
        (*root)->balance++;
        (*root)->right = insert(&(*root)->right, key, value, errorCode);
        if (!*errorCode) {
            freeTree(root);
            return NULL;
        }
    }
    return balance(*root);
}

Dictionary* search(Dictionary** root, const char* key) {
    if (*root == NULL) return NULL;

    int cmp = strcmp(key, (*root)->key);

    if (cmp < 0) {
        return search(&(*root)->left, key);
    } else if (cmp > 0) {
        return search(&(*root)->right, key);
    } else {
        return *root;
    }
}

Dictionary* deleteElement(Dictionary** root, const char* key, bool* errorCode) {
    Dictionary* node = search(root, key);

    if (node == NULL) {
        *errorCode = false;
        return *root;
    }

    free((char*)node->key);
    free((char*)node->value);

    if (node->left == NULL && node->right == NULL) {
        if (node->parent != NULL) {
            if (node->parent->left == node) {
                node->parent->left = NULL;
            } else {
                node->parent->right = NULL;
            }
            free(node);
        } else {
            free(node);
            *root = NULL;
            return *root;
        }
    } else if (node->left != NULL && node->right != NULL) {
        Dictionary* minNode = node->right;
        while (minNode->left != NULL) {
            minNode = minNode->left;
        }

        const char* minNodeKey = minNode->key;
        const char* minNodeValue = minNode->value;

        deleteElement(root, minNode->key, errorCode);

        node->key = myStrdup(minNodeKey);
        if (!*errorCode) {
            freeTree(root);
            return NULL;
        }
        node->value = myStrdup(minNodeValue);
        if (!*errorCode) {
            freeTree(root);
            return NULL;
        }
    } else {
        Dictionary* child = (node->left != NULL) ? node->left : node->right;

        if (node->parent == NULL) {
            *root = child;
            child->parent = NULL;
        } else {
            child->parent = node->parent;
            if (node->parent->left == node) {
                node->parent->left = child;
            } else {
                node->parent->right = child;
            }
        }
        free(node);
    }
    return balance(*root);
}
