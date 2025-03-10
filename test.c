#include "test.h"
#include "solution.h"

bool test(void) {
	if (count(3, 3) != 2) {
		return false;
	}
	if (count(7, 3) != 4) {
		return false;
	}
	if (count(1, 1) != 1) {
		return false;
	}
}
