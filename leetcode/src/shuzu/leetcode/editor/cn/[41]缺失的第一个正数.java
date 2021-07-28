package shuzu.leetcode.editor.cn;

//给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。 
//请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,0]
//输出：3
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,4,-1,1]
//输出：2
// 
//
// 示例 3： 
//
// 
//输入：nums = [7,8,9,11,12]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5 * 105 
// -231 <= nums[i] <= 231 - 1 
// 
// Related Topics 数组 哈希表 
// 👍 1146 👎 0

import java.util.HashMap;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0 || nums[i] > len || nums[i] == (i+1) || nums[i] == nums[nums[i] - 1]) continue;
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
            i--;
        }
        for (int i = 0; i < len; i++) {
            if (i != nums[i] - 1)
                return i+1;
        }
        return len + 1;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
