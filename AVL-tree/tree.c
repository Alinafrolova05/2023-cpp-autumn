#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"

void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root->value);
    free(root);
}

Node* rotateLeft(Node* node) {
    Node* b = node->right;
    node->right = b->left;
    b->left = node;
    return b;
}

Node* rotateRight(Node* node) {
    Node* a = node->left;
    node->left = a->right;
    a->right = node;
    return a;
}

Node* bigRotateLeft(Node* node) {
    Node* c = node->right->left;
    node->right->left = c->right;
    c->right = node->right;
    node->right = c->left;
    c->left = node;
    return c;
}

Node* bigRotateRight(Node* node) {
    Node* c = node->left->right;
    node->left->right = c->left;
    c->left = node->left;
    node->left = c->right;
    c->right = node;
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

Node* insert(Node** root, Node* node) {
    if (*root == NULL) {
        *root = node;
        (*root)->balance = 0;
        return *root;
    }
    if (node->key < (*root)->key) {
        (*root)->left = insert(&(*root)->left, node);
        --(*root)->balance;
    }
    else if (node->key == (*root)->key) {
        char* tmp = (*root)->value;
        (*root)->value = node->value;
        free(tmp);
        free(node);
        return *root;
    }
    else {
        (*root)->right = insert(&(*root)->right, node);
        ++(*root)->balance;
    }
    return balance(*root);
}

Node* deleteElement(Node* root, int key) {
    Node* parent = NULL;
    Node* node = root;

    while (node != NULL && node->key != key) {
        parent = node;
        if (key < node->key) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }

    if (node == NULL) {
        printf("Element not found.\n");
        return root;
    }

    if (node->left == NULL && node->right == NULL) {
        free(node->value);
        free(node);
        if (parent == NULL) {
            return NULL;
        }
        else if (parent->left == node) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
    }
    else if (node->left != NULL && node->right != NULL) {
        Node* minNode = node->right;
        while (minNode->left != NULL) {
            minNode = minNode->left;
        }

        node->key = minNode->key;
        char* tmpValue = node->value;
        node->value = minNode->value;

        node->right = deleteElement(node->right, minNode->key);
    }
    else {
        Node* child = NULL;
        if (node->left != NULL) {
            child = node->left;
        }
        else {
            child = node->right;
        }

        if (parent == NULL) {
            return child;
        }
        else if (parent->left == node) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }

        free(node->value);
        free(node);
    }
}

Node* search(Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->key) {
        return search(root->left, key);
    }
    else if (key > root->key) {
        return search(root->right, key);
    }
    else {
        return root;
    }
}

bool test(void) {
    Node* root = NULL;
    int array[] = { 9, 11, 13, 17, 19 };
    int arraySize = sizeof(array) / sizeof(array[0]);
    int check = 0;

    for (int i = 0; i < arraySize; ++i) {
        Node* node = (Node*)calloc(1, sizeof(Node));
        node->key = array[i];
        node->value = NULL;
        root = insert(&root, node);
    }
    if (!search(root, 13)) {
        check++;
    }
    deleteElement(root, 13);
    if (search(root, 13)) {
        check++;
    }
    freeTree(root);
    return check == 0;
}
