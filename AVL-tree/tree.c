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

char* my_strdup(const char* str) {
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
    Node* b = node->right;
    node->right = b->left;
    b->left = node;

    node->left->parent = node;
    b->parent = node->parent;
    node->parent = b;

    return b;
}

Node* rotateRight(Node* node) {
    Node* a = node->left;
    node->left = a->right;
    a->right = node;

    node->left->parent = node;
    a->parent = node->parent;
    node->parent = a;

    return a;
}

Node* bigRotateLeft(Node* node) {
    Node* c = node->right->left;
    node->right->left = c->right;
    c->right = node->right;
    node->right = c->left;
    c->left = node;

    c->left->right->parent = c->left;
    c->right->left->parent = c->right;
    c->parent = node->parent;
    c->left->parent = c;
    c->right->parent = c;

    return c;
}

Node* bigRotateRight(Node* node) {
    Node* c = node->left->right;
    node->left->right = c->left;
    c->left = node->left;
    node->left = c->right;
    c->right = node;

    c->left->right->parent = c->left;
    c->right->left->parent = c->right;
    c->parent = node->parent;
    c->left->parent = c;
    c->right->parent = c;

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
        newNode->key = my_strdup(key);
        newNode->value = my_strdup(value);
        newNode->balance = 0;
        newNode->parent = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
        return newNode;
    }
    if (strcmp(key, (*root)->key) < 0) {
        (*root)->left = insert(&(*root)->left, key, value, errorCode);
        (*root)->left->parent = *root;
        --(*root)->balance;
    }
    else if (strcmp(key, (*root)->key) == 0) {
        free((char*)(*root)->value);
        (*root)->value = my_strdup(value);
        return *root;
    }
    else {
        (*root)->right = insert(&(*root)->right, key, value, errorCode);
        (*root)->right->parent = *root;
        ++(*root)->balance;
    }
    return balance(*root);
}

Node* search(Node** root, const char* key) {
    if (*root == NULL) return NULL;

    int cmp = strcmp(key, (*root)->key);

    if (cmp < 0) {
        return search(&(*root)->left, key);
    }
    else if (cmp > 0) {
        return search(&(*root)->right, key);
    }
    else {
        return *root;
    }
}

Node* deleteElement(Node** root, const char* key, bool* errorCode) {
    Node* node = search(root, key);

    if (node == NULL) {
        *errorCode = false;
        return *root;
    }

    if (node->left == NULL && node->right == NULL) {
        if (node->parent != NULL) {
            if (node->parent->left == node) {
                node->parent->left = NULL;
            }
            else {
                node->parent->right = NULL;
            }
            free(node);
        }
        else {
            free(node);
            *root = NULL;
            return *root;
        }
    }
    else if (node->left != NULL && node->right != NULL) {
        Node* minNode = node->right;
        while (minNode->left != NULL) {
            minNode = minNode->left;
        }

        const char* minNodeKey = minNode->key;
        const char* minNodeValue = minNode->value;
        deleteElement(root, minNode->key, errorCode);

        node->key = minNodeKey;
        node->value = minNodeValue;

    }
    else {
        Node* child = (node->left != NULL) ? node->left : node->right;

        if (node->parent == NULL) {
            *root = child;
            return*root;
        }
        else {
            child->parent = node->parent;
            if (node->parent->left == node) {
                node->parent->left = child;
            }
            else {
                node->parent->right = child;
            }
        }
        free(node);
    }

    return balance(*root);
}

bool test(void) {
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

bool test2(void) {
    bool errorCode = true;
    Node* root = NULL;
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < 1000000; ++i) {
        char key = (char)('a' + (rand() % 26));
        char value = (char)('a' + (rand() % 26));

        if (insert(&root, (const char*)&key, (const char*)&value, &errorCode) == NULL) {
            errorCode = false;
        }
    }

    freeTree(&root);
    return errorCode;
}

void solution(Node** root) {
    bool errorCode = true;
    int answer = -1;

    while (answer != 0) {
        printf("\nSpecify the option number:\n0.Exit\n1.Add value by key\n2.Get value by key\n3.Check for key availability\n4.Delete key.");
        printf("\nNumber of option: ");
        scanf("%d", &answer);
        getchar();
        if (answer == 0) {
            break;
        }
        else if (answer == 1) {
            char addingKey[256] = "";
            printf("\nWrite the key: ");
            fgets(addingKey, sizeof(addingKey), stdin);
            addingKey[strcspn(addingKey, "\n")] = 0;

            char addingValue[256];
            printf("\nWrite the key value with less than 100 characters: ");
            fgets(addingValue, sizeof(addingValue), stdin);
            addingValue[strcspn(addingValue, "\n")] = 0;

            insert(root, addingKey, addingValue, NULL);
        }
        else if (answer == 2 || answer == 3) {
            char addingKey[256] = "";
            printf("\nSpecify the key: ");
            fgets(addingKey, sizeof(addingKey), stdin);
            addingKey[strcspn(addingKey, "\n")] = 0;

            Node* found = search(root, addingKey);
            if (found == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                printf("\nValue: %s", found->value);
            }
        }
        else if (answer == 4) {
            char addingKey[256];
            printf("\nSpecify the key: ");
            fgets(addingKey, sizeof(addingKey), stdin);
            addingKey[strcspn(addingKey, "\n")] = 0;

            if (search(root, addingKey) == NULL) {
                printf("\nThere is no such key in the dictionary.");
            }
            else {
                deleteElement(root, addingKey, NULL);
                printf("\nThe value and key have been deleted.");
            }
        }
        else {
            printf("\nInput wrong!");
            break;
        }
    }
}