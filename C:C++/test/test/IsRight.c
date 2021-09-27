#include <stdio.h>
#include "RightEvaluation.h"
#include "WrongEvaluation.h"

int IsRight(int number, int answer)
{
	if(answer == number){
		RightEvaluation();
		return 1;
		
	}
	else{
		WrongEvaluation();
		return 0;
	}
}
