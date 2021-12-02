package shuzu.leetcode.editor.cn;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ll = new ArrayList<>();
        //to deal with special case
        if (nums.length < 3)
            return ll;
        Arrays.sort(nums);
        if (nums[nums.length - 1] < 0 ||nums[0] > 0)
            return ll;

        for (int i = 0; i < nums.length-2; i++) {
            if (i != 0&&nums[i] == nums[i-1])   continue;
            int temp = nums.length-1;
            int k;
            for (int j = i+1; j < nums.length-1; j++) {
                if (nums[j] == nums[j-1] && j != i+1) continue;
                for (k = temp; k > j ; k--) {
                    if (k != (nums.length-1)&&nums[k] == nums[k+1]) continue;
                    if (nums[i] + nums[j] +nums[k] < 0) {
                        temp = k;
                        break;
                    }
                    if (nums[i] + nums[j] +nums[k] == 0 ) {
                        List<Integer> list = new ArrayList<>();
                        list.add(nums[i]);
                        list.add(nums[j]);
                        list.add(nums[k]);
                        ll.add(list);
                        temp = k-1;
                        break;
                    }
                }
                if (k==j)   break;
            }
        }
        return ll;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
