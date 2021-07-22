package shuzu.leetcode.editor.cn;

//实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。 
//
// 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。 
//
// 必须 原地 修改，只允许使用额外常数空间。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[1,3,2]
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[1,2,3]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,1,5]
//输出：[1,5,1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 100 
// 
// Related Topics 数组 双指针 
// 👍 1232 👎 0

import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public void nextPermutation(int[] nums) {
        //Descending Order
        if (order(nums)) {
            Arrays.sort(nums);
            return;
        }
        //common case
        int temp;
        int i;
        for (i = nums.length - 2; i >= 0 ; i--) {
            int min = nums[i+1];
            int dot = i+1;
            for (int j = i+1; j < nums.length; j++) {
                if (nums[j] < min && nums[j] > nums[i]){
                    min = nums[j];
                    dot = j;
                }
            }
            if (min > nums[i]) {
                temp = nums[i];
                nums[i] = nums[dot];
                nums[dot]  = temp;
                break;
            }
        }
        Arrays.sort(nums,i+1, nums.length);
        return;
    }
    boolean order (int[] nums) {
        for (int i = 0; i < nums.length-1; i++) {
            if (nums[i] < nums[i+1])
                return false;
        }
        return true;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
