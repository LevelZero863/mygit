//
//  Comments.c
//  project6.3
//
//  Created by EthanLeslie on 2021/9/16.
//

#include "Comments.h"
#include <stdlib.h>
#include <stdio.h>

void Comments(int n){//1-->RIGHT,0-->WRONG
    int num=rand()%4+1;
    if(n==1){
        switch (num) {
            case 1:
                printf("Very good!\n");
                break;
            case 2:
                printf("Excellent！\n");
                break;
            case 3:
                printf("Nice work！\n");
                break;
            case 4:
                printf("Keep up the good work!\n");
                break;
        }
    }else{
        switch (num) {
            case 1:
                printf("No. Please try again!\n");
                break;
            case 2:
                printf("Wrong.  Try once more!\n");
                break;
            case 3:
                printf("Don’t give up! \n");
                break;
            case 4:
                printf("Not correct. Keep trying!\n");
                break;
        }
    }
}
