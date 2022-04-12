//
//  Solution.cpp
//  1336
//
//  Created by EthanLeslie on 2022/1/22.
//

#include "Solution.hpp"
#include <string>
#include <algorithm>
class Solution {
public:
    int removePalindromeSub(string s) {
        string n = s;
        reverse(n.begin(),n.end());
        if (n == s) return 1;
        return 2;
    }
};
