#include<stdio.h>
#include<time.h>
#include "IsRight.h"
#include "guess.h"
#include "makeop.h"

void guess(){
	int answer;
	int count = 0;
	int flag = 1;
	int i;
	int number;
	do
	{
		int sum = 0;
		for (i = 0;i<10;i++)
		{
			srand(time(NULL));
			int a = makenumber();
			int op = makeop();
			int b = makenumber();
			//printf("%d%d%d=?\n",a,op, b);
			scanf("%d", &answer);
			switch(op){
				case 1: number= a + b;
				case 2: number = a - b;
				case 3: number = a * b;
				case 4: number = a / b;
				default:printf("´íÎó£¡\n");
				return 0;
			}
			//int number = a * b;
			if (IsRight(number,answer))
			{
				sum += 10;
			}
		}
		if (sum >75)
		{
			flag = 0;
		}
		printf("×Ü·Ö%d\n",sum); 
	}while(flag);
}
