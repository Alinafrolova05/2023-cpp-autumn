#pragma once

#include <stdbool.h>

// Tests the left rotation operation on the tree.
// Returns true if the test is successful, otherwise false.
bool testRotateLeft(void);

// Tests the right rotation operation on the tree.
// Returns true if the test is successful, otherwise false.
bool testRotateRight(void);

// Tests the big left rotation operation on the tree,
// which may be used when a more significant restructuring is needed.
// Returns true if the test is successful, otherwise false.
bool testBigRotateLeft(void);

// Tests the big right rotation operation on the tree,
// which may be used when a more significant restructuring is needed.
// Returns true if the test is successful, otherwise false.
bool testBigRotateRight(void);

// Runs a performance test by inserting a large number of random elements into the tree.
// Returns true if all insertions are successful, otherwise false.
bool testRandomInsertions(void);

// Tests other functions of the tree (e.g., search, deletion, etc.)
// to ensure they work correctly. Returns true if all tests are successful, otherwise false.
bool testOtherFunctions(void);

// Main testing function that may call all previous test functions
// and returns true if all tests are successful, otherwise false.
bool test(void);
