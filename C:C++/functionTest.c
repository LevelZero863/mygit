//
// Created by EthanLeslie on 2021/9/13.
//
#include <stdio.h>
int add (int sum,int num);
int func (int n);
int main() {
    int n;
    printf("please enter...");
    scanf("%d",&n);
    int sum;
    while(n>=1){
        int nn = func(n);
        sum = add(sum,nn);
        n--;
    }
    printf("The result is %d",sum);
    return 0;
}
int add (int sum,int num) {
     return sum+num;
}
int func (int n) {
    int ret = 1;
    while(n>=1){
        ret *= n;
        n--;
    }
    return ret;
}