//
//  main.cpp
//  array
//
//  Created by EthanLeslie on 2021/9/14.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int matrix[4][4];
    int i,j;
    for(i=0;i<4;i++){
        for (j=0;j<4; j++) {
            cin>>matrix[i][j];
        }
    }
    int line,row;
    line=0;
    row=0;
    for (i=0; i<4; i++) {
        for(j=0;j<4;j++){
            line+=matrix[i][j];
            if(j==3){
                if(i==0){
                    cout<<"the sum of the first line is "<<line<<endl;
                } else if (i==1){
                    cout<<"the sum of the second line is "<<line<<endl;
                }else if (i==2){
                    cout<<"the sum of the second line is "<<line<<endl;
                }else{
                    cout<<"the sum of the second line is "<<line<<endl;
                }
                line=0;
            }
        }
    }
    return 0;
}
