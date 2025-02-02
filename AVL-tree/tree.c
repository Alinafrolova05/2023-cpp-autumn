#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

char* myStrdup(const char* str) {
    if (str == NULL) return NULL;
    size_t len = strlen(str) + 1;
    char* copy = (char*)malloc(len);
    if (copy) {
        strcpy(copy, str);
    }
    return copy;
}

void freeTree(Node** root) {
    if (*root == NULL) return;
    freeTree(&((*root)->left));
    freeTree(&((*root)->right));
    free((char*)(*root)->key);
    free((char*)(*root)->value);
    free(*root);
}

Node* rotateLeft(Node* node) {
    if (node == NULL || node->right == NULL) {
        return node;
    }

    Node* b = node->right;
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

Node* rotateRight(Node* node) {
    if (node == NULL || node->left == NULL) {
        return node;
    }

    Node* a = node->left;
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

Node* bigRotateLeft(Node* node) {
    if (node == NULL || node->right == NULL || node->right->left == NULL) {
        return node;
    }

    Node* c = node->right->left;
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

Node* bigRotateRight(Node* node) {
    if (node == NULL || node->left == NULL || node->left->right == NULL) {
        return node;
    }

    Node* c = node->left->right;
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

Node* balance(Node* node) {
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

Node* insert(Node** root, const char* key, const char* value, bool* errorCode) {
    if (*root == NULL) {
        Node* newNode = (Node*)calloc(1, sizeof(Node));
        if (newNode == NULL) {
            *errorCode = false;
            return NULL;
        }
        newNode->key = myStrdup(key);
        newNode->value = myStrdup(value);
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
    } else if (strcmp(key, (*root)->key) == 0) {
        return *root;
    } else {
        (*root)->balance++;
        (*root)->right = insert(&(*root)->right, key, value, errorCode);
    }
    return balance(*root);
}

Node* search(Node** root, const char* key) {
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

Node* deleteElement(Node** root, const char* key, bool* errorCode) {
    Node* node = search(root, key);

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
        Node* minNode = node->right;
        while (minNode->left != NULL) {
            minNode = minNode->left;
        }

        const char* minNodeKey = minNode->key;
        const char* minNodeValue = minNode->value;

        deleteElement(root, minNode->key, errorCode);

        node->key = myStrdup(minNodeKey);
        node->value = myStrdup(minNodeValue);
    } else {
        Node* child = (node->left != NULL) ? node->left : node->right;

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
