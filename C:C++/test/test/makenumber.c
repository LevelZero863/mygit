#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "makenumber.h"
#define MAX_NUMBER 10
#define MIN_NUMBER 1

int makenumber(void){
	int number;
//	srand(time(NULL));
	number = (rand() % (MAX_NUMBER - MIN_NUMBER + 1)) + MIN_NUMBER;
	return number;
}
