package shuzu.leetcode.editor.cn;

//给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。 
//
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。 
//
// 
//
// 
//
// 示例 1: 
//
// 
//输入: numRows = 5
//输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// 
//
// 示例 2: 
//
// 
//输入: numRows = 1
//输出: [[1]]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= numRows <= 30 
// 
// Related Topics 数组 动态规划 
// 👍 570 👎 0

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i <= numRows; i++) {
            if (i == 1) {
                list.add(1);
                ans.add(new ArrayList<>(list));
            } else if (i == 2) {
                list.add(1);
                list.add(1);
                ans.add(new ArrayList<>(list));
            } else {
                list.add(1);
                for (int j = 0; j < i-2; j++) {
                    int sum = ans.get(i-2).get(j) + ans.get(i-2).get(j+1);
                    list.add(sum);
                }
                list.add(1);
                ans.add(new ArrayList<>(list));
            }
            list.clear();
        }
        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
