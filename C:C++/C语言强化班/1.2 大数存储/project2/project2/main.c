//
//  main.c
//  project2
//
//  Created by EthanLeslie on 2021/9/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int result[1000];
    int i,j,k;
    for (i=0; i<1000; i++) {
        result[i]=0;
    }
    result[0]=1;
    int len=1;
    int a,b,c;
    for(i=1;i<=40;i++){
        b=0;
        for (k=0; k<len; k++) {
            a=result[k]*i+b;//末尾与当前数的乘积
            b=a/10;//进位
            c=a%10;//当前位的值
            result[k]=c;
        }
        while(b){
            result[len++]=b%10;
            b/=10;
        }
        for (j=len-1; j>=0; j--) {
            printf("%d",result[j]);
        }
        printf("\n");
    }
    
}
/*
 1
 2
 6
 24
 120
 720
 5040
 
 */
