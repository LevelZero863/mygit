//
//  Solution.cpp
//  Chapter2
//
//  Created by EthanLeslie on 2022/1/13.
//

#include "Solution.hpp"
#include <vector>
#include <algorithm>
using namespace ::std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int index = 0;
        int temp;
        if (nums[1] > nums[0]) {
            temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            index = 1;
        }
        for (int i = 2; i<nums.size(); i++) {
            if (nums[i] > nums[0]) {
                index = i;
                temp = nums[0];
                nums[0] = nums[i];
                nums[1] = temp;
            } else if (nums[i] > nums[1]) {
                nums[1] = nums[i];
            }
        }
        if (nums[1]*2 <= nums[0])
            return index;
        return -1;
    }
};
