package shuzu.leetcode.editor.cn;

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。 
//
// 如果数组中不存在目标值 target，返回 [-1, -1]。 
//
// 进阶： 
//
// 
// 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 8
//输出：[3,4] 
//
// 示例 2： 
//
// 
//输入：nums = [5,7,7,8,8,10], target = 6
//输出：[-1,-1] 
//
// 示例 3： 
//
// 
//输入：nums = [], target = 0
//输出：[-1,-1] 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 105 
// -109 <= nums[i] <= 109 
// nums 是一个非递减数组 
// -109 <= target <= 109 
// 
// Related Topics 数组 二分查找 
// 👍 1115 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int[] searchRange(int[] nums, int target) {
        //length = 0
        int len = nums.length;
        for (int i = 0,j = len-1; i <= j;) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                int left = mid,right = mid;
                while(left >= 0) {
                    if (nums[left] != target){
                        left++;
                        break;
                    }
                    if (left-1 >= 0) left--;
                    else break;
                }
                while(right < len) {
                    if (nums[right] != target){
                        right--;
                        break;
                    }
                    if (right+1 < len)  right++;
                    else break;
                }
                return new int[]{left,right};
            }else if (target > nums[mid]) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }

        }
        return new int[]{-1, -1};
    }
}
//leetcode submit region end(Prohibit modification and deletion)
