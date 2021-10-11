//
//  JudgeAnswer.c
//  project6.3
//
//  Created by EthanLeslie on 2021/9/16.
//

#include <stdio.h>
#include "MakeOperator.h"
#include "JudgeAnswer.h"
void JudgeAnswer(int number1,int number2,char* replay){
    int op=MakeOperator();
    int true = 0;
    char ch = '\0';
    switch (op) {
        case 1:
            ch='+';
            true=number1+number2;
            break;
        case 2:
            ch='-';
            true=number1-number2;
            break;
        case 3:
            ch='*';
            true=number1*number2;
            break;
        case 4:
            ch='/';
            true=number1/number2;
    }
    printf("The question is %d %c %d\n",number1,ch,number2);
    printf("Please enter your answer:");
    int a;
    scanf("%d",&a);
    if (a==true) {
        *replay='Y';
    }else{
        *replay='N';
    }
}
