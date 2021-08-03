package shuzu.leetcode.editor.cn;

//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SE
//E"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
// Related Topics 数组 回溯 矩阵 
// 👍 973 👎 0

import java.util.ArrayList;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean exist(char[][] board, String word) {
        boolean[][] visited = new boolean[board.length+1][board[0].length+1];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == word.charAt(0)) {
                    visited[i][j] = true;
                    dfs(board,word,0,i,j,visited);
                    if (visited[board.length][board[0].length] == true)
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
    void  dfs (char[][] board, String word, int index, int x, int y,boolean[][] visited) {
        if (index == word.length() - 1) {
            visited[board.length][board[0].length] = true;
            return;
        }
        if (x - 1 >= 0 && visited[x-1][y] == false&& word.charAt(index+1) == board[x-1][y]) {
            visited[x-1][y] = true;
            dfs(board,word,index+1,x-1,y,visited);
            visited[x-1][y] = false;
        }
        if (y - 1 >= 0 && visited[x][y-1] == false&& word.charAt(index+1) == board[x][y-1]) {
            visited[x][y-1] = true;
            dfs(board,word,index+1,x,y-1,visited);
            visited[x][y-1] = false;
        }
        if (x + 1 <= board.length-1&& visited[x+1][y] == false&& word.charAt(index+1) == board[x+1][y]) {
            visited[x+1][y] = true;
            dfs(board,word,index+1,x+1,y,visited);
            visited[x+1][y] = false;
        }
        if (y + 1 <= board[0].length-1 && visited[x][y+1] == false&& word.charAt(index+1) == board[x][y+1]) {
            visited[x][y+1] = true;
            dfs(board,word,index+1,x,y+1,visited);
            visited[x][y+1] = false;
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
