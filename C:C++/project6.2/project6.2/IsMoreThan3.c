//
//  IsMoreThan3.c
//  project6.2
//
//  Created by EthanLeslie on 2021/9/16.
//

#include "IsMoreThan3.h"
#include <stdio.h>
int IsMoreThan3(int flag){
    if(flag==3){
        printf("Wrong！You have tried three times! Test over!\n");
        return 1;
    }
    return 0;
}
