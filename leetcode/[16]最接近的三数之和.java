package shuzu.leetcode.editor.cn;

//给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和
//。假定每组输入只存在唯一答案。 
//
// 
//
// 示例： 
//
// 输入：nums = [-1,2,1,-4], target = 1
//输出：2
//解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 10^3 
// -10^3 <= nums[i] <= 10^3 
// -10^4 <= target <= 10^4 
// 
// Related Topics 数组 双指针 排序 
// 👍 827 👎 0

import java.util.Arrays;
import java.util.Map;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ret = 100000;

        for (int i = 0; i < nums.length - 2; i++) {
            int  right = nums.length - 1;
            for (int j = i+1; j < right;) {
                if (nums[i] + nums[j] + nums[right] == target)  return target;
                if (Math.abs(nums[i] + nums[j] + nums[right] - target) < Math.abs(ret - target))
                    ret = nums[i] + nums[j] + nums[right];
                if (nums[i] + nums[j] + nums[right] >= target)   right--;
                else   j++;
            }
        }
        return ret;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
