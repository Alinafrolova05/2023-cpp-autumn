#pragma once

#include <stdbool.h>

// Structure for an element in the hash table
typedef struct Element Element;

// Structure for a segment in the hash table
typedef struct Segment Segment;

// Inserts a new element with the given key into the hash table segment
void insert(Segment** segment, char* key, bool* errorCode);

// Searches for an element with the given key in the hash table segment; returns true if found, otherwise false
bool search(Segment* segment, char* key);

// Frees the memory occupied by the hash table segments
void freeSegments(Segment** segment);

// Retrieves a value from the segment, possibly based on some criteria
Element* getValue1(Segment* segment);

// Gets a string value from the element
char* getValue2(Element* element);

// Gets an integer value from the element
int getValue3(Element* element);

// Retrieves the next segment from the current segment
Segment* getValue4(Segment* segment);

// Retrieves the next element from the current element
Element* getValue5(Element* element);
