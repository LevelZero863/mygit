//
//  main.c
//  project6
//
//  Created by EthanLeslie on 2021/9/16.
//

#include <stdio.h>
#include <stdio.h>
#include "MakeNumber.h"
#include "JudgeAnswer.h"
int main(int argc, const char * argv[]) {
    int number1;
    int number2;
    char* replay1;
    char replay2;
    replay1=&replay2;
    char p;
    do{
        number1=MakeNumber();
        number2=MakeNumber();
        JudgeAnswer(number1,number2,replay1);
        if(replay2=='N'){
            printf("Wrong!Try again.\n");
        }
        if(replay2=='Y'){
            printf("Right!");
            printf("Do you want to continue(Y/N or y/n)?\n");
            scanf("%s",&p);
            if (p=='Y'||p=='y') {
                replay2='N';
            }else
                replay2='Y';
        }
    }while(replay2=='N'||replay2=='n');
    return 0;
}