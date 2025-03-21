#include "tree.h"

bool test(void) {
	bool errorCode = true;
	char str[20] = "(+3(*45))";
	if (countResult(str, &errorCode) != 23 || !errorCode) {
		return false;
	}
	char str2[20] = "(+3(/40)";
	countResult(str2, &errorCode);
	if (errorCode) {
		return false;
	}
	return true;
}
