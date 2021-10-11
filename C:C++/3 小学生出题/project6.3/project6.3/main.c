//
//  main.c
//  project6.3
//
//  Created by EthanLeslie on 2021/9/16.
//

#include <stdio.h>
#include <stdio.h>
#include "MakeNumber.h"
#include "JudgeAnswer.h"
#include "ControlNum.h"
#include "CheckCorrect.h"
int main(int argc, const char * argv[]) {
    int count;
    do{
        count=ControlNum(10);
        printf("The grade is %d\n",count*10);
    }while(CheckCorrect(count));
    return 0;
}
