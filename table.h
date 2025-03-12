#pragma once

#include <stdbool.h>
#include "list.h"

// Defines the structure.
typedef struct HashTable HashTable;

// Returns the size of the hash table.
int getSizeTable(HashTable* table);

// Returns the number of elements currently stored in the hash table.
int getHashTableElementCount(HashTable* table);

// Searches for an element in the hash table.
Element* search(HashTable* hashTable, const char* key);

// Inserts a new element with the specified key into the hash table.
void insertInTable(HashTable* hashTable, const char* key, bool* errorCode);

// Frees the memory allocated for the hash table and all its elements.
void freeTable(HashTable* hashTable);

// Prints the contents of the hash table.
void printTable(HashTable* hashTable);

// Creates a new hash table with the specified initial size.
HashTable* createHashTable(int initialSize, bool* errorCode);

// Calculates and returns the load factor of the hash table.
double calcuHashTableFillFactor(HashTable* hashTable);

// Calculates and returns the average length of the lists in the hash table.
double calcuLateAverageListLength(HashTable* hashTable);

// Calculates and returns the maximum length of any list in the hash table.
int calcuLateMaxListLength(HashTable* hashTable);
