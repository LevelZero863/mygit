#include <stdio.h>
#include <time.h>

void RightEvaluation() {
	int i;
	i = rand() % 4 + 1;
	switch (i) {
	case 1:printf("Very good!\n");
		break;
	case 2:printf("Excellent!\n");
		break;
	case 3:printf("Nice work!\n");
		break;
	case 4:printf("Keep up the good work!\n");
		break;
	default:printf("Wrong type!");
	}
}
