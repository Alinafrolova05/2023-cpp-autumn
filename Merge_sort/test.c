#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "sort.h"

bool testSortByName(void) {
	Number phone[3] = { {"Dmitry", "12345"}, {"Sergey", "67891"}, {"Anna", "01112"} };
	Number correct[3] = { {"Anna", "01112"}, {"Dmitry", "12345"}, {"Sergey", "67891"} };
	mergeSort(phone, 3, SORT_BY_NAME);

	for (int i = 0; i < 3; i++) {
		if (strcmp(phone[i].name, correct[i].name) != 0 || strcmp(phone[i].number, correct[i].number) != 0) {
			return false;
		}
	}
	return true;
}

bool testSortByNumber(void) {
	Number phone[3] = { {"Sergey", "67891"}, {"Anna", "01112"} , {"Dmitry", "12345"} };
	Number correct[3] = { {"Anna", "01112"}, {"Dmitry", "12345"}, {"Sergey", "67891"} };
	mergeSort(phone, 3, SORT_BY_NAME);

	for (int i = 0; i < 3; i++) {
		if (strcmp(phone[i].name, correct[i].name) != 0 || strcmp(phone[i].number, correct[i].number) != 0) {
			return false;
		}
	}
	return true;
}
