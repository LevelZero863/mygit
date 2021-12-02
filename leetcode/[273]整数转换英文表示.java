package shuzu.leetcode.editor.cn;

//将非负整数 num 转换为其对应的英文表示。 
//
// 
//
// 示例 1： 
//
// 
//输入：num = 123
//输出："One Hundred Twenty Three"
// 
//
// 示例 2： 
//
// 
//输入：num = 12345
//输出："Twelve Thousand Three Hundred Forty Five"
// 
//
// 示例 3： 
//
// 
//输入：num = 1234567
//输出："One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
// 
//
// 示例 4： 
//
// 
//输入：num = 1234567891
//输出："One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven 
//Thousand Eight Hundred Ninety One"
// 
//
// 
//
// 提示： 
//
// 
// 0 <= num <= 2³¹ - 1 
// 
// Related Topics 递归 数学 字符串 👍 220 👎 0

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    Map<Integer,String> num1 = new HashMap<>();
    Map<Integer,String> num2 = new HashMap<>();
    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        num1.put(0,"Zero");
        num1.put(1,"One");
        num1.put(2,"Two");
        num1.put(3,"Three");
        num1.put(4,"Four");
        num1.put(5,"Five");
        num1.put(6,"Six");
        num1.put(7,"Seven");
        num1.put(8,"Eight");
        num1.put(9,"Nine");
        num2.put(2,"Twenty");
        num2.put(3,"Thirty");
        num2.put(4,"Forty");
        num2.put(5,"Fifty");
        num2.put(6,"Sixty");
        num2.put(7,"Seventy");
        num2.put(8,"Eighty");
        num2.put(9,"Ninety");
        List<String> ans = new ArrayList<>();
        f(num,"",ans,1);
        if (ans.get(0) == "") {
            ans.remove(0);
        }
        String a = new String("");
        for (int i = ans.size() - 1; i >= 0; i--) {
            a += ans.get(i);
            if (i != 0)
                a += " ";
        }
        return a;
    }
    void f(int num, String s, List<String> ans, int level) {
        if (num == 0){
            return ;
        }
        ans.add(s);
        int s1,s2;
            s1 = num % 10;
            num /= 10;
            s2 = num % 10;
            num /= 10;
            if (s2 == 1) {
                switch (s1) {
                    case 0:
                        ans.add("Ten");
                        break;
                    case 1:
                        ans.add("Eleven");
                        break;
                    case 2:
                        ans.add("Twelve");
                        break;
                    case 3:
                        ans.add("Thirteen");
                        break;
                    case 4:
                        ans.add("Fourteen");
                        break;
                    case 5:
                        ans.add("Fifteen");
                        break;
                    case 6:
                        ans.add("Sixteen");
                        break;
                    case 7:
                        ans.add("Seventeen");
                        break;
                    case 8:
                        ans.add("Eighteen");
                        break;
                    case 9:
                        ans.add("Nineteen");
                        break;
                }
            } else {
                if (s1 != 0) {
                    ans.add(num1.get(s1));
                }
                if (s2 != 0) {
                    ans.add(num2.get(s2));
                }
            }
        if (s1 == 0 && s2 == 0 && (num %10) == 0) ans.remove(ans.size()-1);
        if (num > 0) {
            s1 = num % 10;
            num /= 10;
            if (s1 != 0 ) {
                ans.add("Hundred");
                ans.add(num1.get(s1));
            }
        }
        level ++;
        String next;
        if (level == 2) {
            next = new String("Thousand");
        } else if (level == 3) {
            next = new String("Million");
        } else {
            next = new String("Billion");
        }
        f(num,next,ans,level);
    }
}
//leetcode submit region end(Prohibit modification and deletion)
