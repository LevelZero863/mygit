#include <stdio.h>
#include <time.h>
#include "makenumber.h"
#define MAX_NUMBER 10
#define MIN_NUMBER 1

int makeop(void){
int op;
	op = rand() % 4 + 1;
	switch (op) {
	case 1:return 1;
	case 2:return 2;
	case 3:return 3;
	case 4:return 4;
//	char op;
////	srand(time(NULL));
//	op = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
//	return number;
}
