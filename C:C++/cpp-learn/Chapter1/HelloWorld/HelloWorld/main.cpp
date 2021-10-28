//
//  main.cpp
//  HelloWorld
//
//  Created by EthanLeslie on 2021/10/22.
//

#include <iostream>
using namespace::std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int num = 1;
    while (num < 10e9) {
        cout<<num<<endl;
        num *= 2;
    }
    return 0;
}
