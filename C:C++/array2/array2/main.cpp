//
//  main.cpp
//  array2
//
//  Created by EthanLeslie on 2021/9/14.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool operator()(string const &s1,string const &s2)const
    {
        if(s1.size()<s2.size())
            return true;
        if(s1.size()==s2.size())
            return strcmp(s1, s2)<0;
        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        
    }
};
