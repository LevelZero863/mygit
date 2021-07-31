package shuzu.leetcode.editor.cn;

//给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。 
//
//
//
// 示例 1： 
//
// 
//输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
//输出：[1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//输出：[1,2,3,4,8,12,11,10,9,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 10 
// -100 <= matrix[i][j] <= 100 
// 
// Related Topics 数组 矩阵 模拟 
// 👍 831 👎 0

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int m = matrix.length; //line
        int n = matrix[0].length; //row
        int flag = 1;//1-->right,2-->down,3-->left,4-->up
        int bound1 = n-1;
        int bound2 = m-1;
        int bound3 = 0;
        int bound4 = 1;
        ans.add(matrix[0][0]);
        int x = 0,y = 0;
        while (true) {
            if (flag == 1) {
                if (y <= bound1) break;
                for (int i = y + 1; i <= bound1; i++)
                    ans.add(matrix[x][i]);
                y = bound1;
                bound1--;
                flag = 2;
            } else if (flag == 2) {
                if (x <= bound2) break;
                for (int i = x + 1; i <= bound2; i++)
                    ans.add(matrix[i][y]);
                x = bound2;
                bound2--;
                flag = 3;
            } else if (flag == 3) {
                if (y >= bound3) break;
                for (int i = y - 1; i >= bound3 ; i--)
                    ans.add(matrix[x][i]);
                y = bound3;
                bound3++;
                flag = 4;
            } else {
                if (x >= bound4) break;
                for (int i = x - 1; i >= bound4 ; i--)
                    ans.add(matrix[x][y--]);
                x = bound4;
                bound4++;
                flag = 1;
            }
        }
        return ans;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
