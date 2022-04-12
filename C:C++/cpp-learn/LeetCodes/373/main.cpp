//
//  main.cpp
//  373
//
//  Created by EthanLeslie on 2022/1/14.
//

#include <iostream>
#include "Solution.hpp"
#include<vector>
using namespace ::std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1({1,1,2});
    vector<int> nums2({1,2,3});
    int k = 10;
    vector<vector<int>> ans;
    Solution solution;
    ans = solution.kSmallestPairs(nums1, nums2, k);
    for (int i = 0; i<ans.size(); i++) {
        cout<<ans[i][0]<<ans[i][1]<<endl;
    }
    return 0;
}
