package shuzu.leetcode.editor.cn;

//给你一个非负整数数组 nums ，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。 
//
// 假设你总是可以到达数组的最后一个位置。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [2,3,1,1,4]
//输出: 2
//解释: 跳到最后一个位置的最小跳跃数是 2。
//     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
// 
//
// 示例 2: 
//
// 
//输入: nums = [2,3,0,1,4]
//输出: 2
// 
//
// 
//
// 提示: 
//
// 
// 1 <= nums.length <= 104 
// 0 <= nums[i] <= 1000 
// 
// Related Topics 贪心 数组 动态规划 
// 👍 1076 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int jump(int[] nums) {
        int len = nums.length;
        if (len == 1) return 0;
        int[] fun = new int[len];
        int max = Math.max(nums[0],nums[1]);
        fun[0] = 0;
        fun[1] = 1;
        for (int i = 2; i < len; i++) {
            int min = Integer.MAX_VALUE;
            for (int j = i - 1; j >= 0&&i - j <= max; j--) {
                if (nums[j] >= i - j&&fun[j] + 1 < min)
                    min = fun[j] + 1;
            }
            fun[i] = min;
            if (nums[i] > max)  max = nums[i];
        }
        return fun[len-1];
    }
}
//leetcode submit region end(Prohibit modification and deletion)
