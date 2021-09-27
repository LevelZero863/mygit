#include <stdio.h>
#include <time.h>

void WrongEvaluation() {
	int i;
	i = rand() % 4 + 1;
	switch (i)
	{
	case 1:printf("No.Please try again.\n");
		break;
	case 2:printf("Wrong.Try once more.\n");
		break;
	case 3:printf("Don't give up!\n");
		break;
	case 4:printf("Not correct.Keep trying.\n");
		break;
	default:printf("Wrong type!");
	}
}

