#include "test.h"
#include "operations.h"

bool testStackOperations(void) {
    bool errorCode = true;

    char str1[20] = "96-12+*";
    if (solution(str1, &errorCode) != 9 || !errorCode) {
        return false;
    }
    
    char str2[20] = "84/2-3+";
    if (solution(str2, &errorCode) != 3 || !errorCode) {
        return false; 
    }

    char str3[20] = "42/0*";
    solution(str3, &errorCode);
    if (!errorCode) {
        return false; 
    }

    char str4[20] = "+*";
    solution(str4, &errorCode);
    if (errorCode) {
        return false;
    }
    errorCode = true;

    char str5[20] = "23+5-";
    if (solution(str5, &errorCode) != 0 || !errorCode) {
        return false;
    }

    char str6[20] = "12+3+4+";
    if (solution(str6, &errorCode) != 10 || !errorCode) {
        return false;
    }

    char str7[20] = "23+4*";
    if (solution(str7, &errorCode) != 20 || !errorCode) {
        return false;
    }

    return true;
}
