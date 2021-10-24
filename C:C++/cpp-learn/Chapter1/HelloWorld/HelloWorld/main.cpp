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
    int sum = 0,num = 0;
    while (cin>>num) {
        sum+=num;
    }
    cout<<sum<<endl;
    return 0;
}
