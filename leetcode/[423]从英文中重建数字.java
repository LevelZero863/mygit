//给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "owoztneoer"
//输出："012"
// 
//
// 示例 2： 
//
// 
//输入：s = "fviefuro"
//输出："45"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁵ 
// s[i] 为 ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"] 这些字符之一 
// s 保证是一个符合题目要求的字符串 
// 
// Related Topics 哈希表 数学 字符串 👍 130 👎 0


import java.util.*;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public String originalDigits(String s) {
        HashMap<Character, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            hashMap.put(s.charAt(i),hashMap.getOrDefault(s.charAt(i),0)+1);
        }
        List<Integer> ans = new ArrayList<>();
        if (hashMap.containsKey('z')&&hashMap.get('z') > 0) {
            int count = hashMap.get('z');
            hashMap.put('z',0);
            hashMap.put('e',hashMap.get('e')-count);
            hashMap.put('r',hashMap.get('r')-count);
            hashMap.put('o',hashMap.get('o')-count);
            for (int i = 0; i < count; i++) {
                ans.add(0);
            }
        }
        if (hashMap.containsKey('w')&&hashMap.get('w') > 0) {
            int count = hashMap.get('w');
            hashMap.put('w',0);
            hashMap.put('t',hashMap.get('t')-count);
            hashMap.put('o',hashMap.get('o')-count);
            for (int i = 0; i < count; i++) {
                ans.add(2);
            }
        }
        if (hashMap.containsKey('u')&&hashMap.get('u') > 0) {
            int count = hashMap.get('u');
            hashMap.put('u',0);
            hashMap.put('f',hashMap.get('f')-count);
            hashMap.put('r',hashMap.get('r')-count);
            hashMap.put('o',hashMap.get('o')-count);
            for (int i = 0; i < count; i++) {
                ans.add(4);
            }
        }
        if (hashMap.containsKey('x')&&hashMap.get('x') > 0) {
            int count = hashMap.get('x');
            hashMap.put('x',0);
            hashMap.put('s',hashMap.get('s')-count);
            hashMap.put('i',hashMap.get('i')-count);
            for (int i = 0; i < count; i++) {
                ans.add(6);
            }
        }
        if (hashMap.containsKey('g')&&hashMap.get('g') > 0) {
            int count = hashMap.get('g');
            hashMap.put('g',0);
            hashMap.put('e',hashMap.get('e')-count);
            hashMap.put('i',hashMap.get('i')-count);
            hashMap.put('h',hashMap.get('h')-count);
            hashMap.put('t',hashMap.get('t')-count);
            for (int i = 0; i < count; i++) {
                ans.add(8);
            }
        }
        if (hashMap.containsKey('o')&&hashMap.get('o') > 0) {
            int count = hashMap.get('o');
            hashMap.put('o',0);
            hashMap.put('n',hashMap.get('n')-count);
            hashMap.put('e',hashMap.get('e')-count);
            for (int i = 0; i < count; i++) {
                ans.add(1);
            }
        }
        if (hashMap.containsKey('t')&&hashMap.get('t') > 0) {
            int count = hashMap.get('t');
            hashMap.put('t',0);
            hashMap.put('h',hashMap.get('h')-count);
            hashMap.put('r',hashMap.get('r')-count);
            hashMap.put('e',hashMap.get('e')-count*2);
            for (int i = 0; i < count; i++) {
                ans.add(3);
            }
        }
        if (hashMap.containsKey('f')&&hashMap.get('f') > 0) {
            int count = hashMap.get('f');
            hashMap.put('f',0);
            hashMap.put('v',hashMap.get('v')-count);
            hashMap.put('i',hashMap.get('i')-count);
            hashMap.put('e',hashMap.get('e')-count);
            for (int i = 0; i < count; i++) {
                ans.add(5);
            }
        }
        if (hashMap.containsKey('s')&&hashMap.get('s') > 0) {
            int count = hashMap.get('s');
            hashMap.put('s',0);
            hashMap.put('v',hashMap.get('v')-count);
            hashMap.put('n',hashMap.get('n')-count);
            hashMap.put('e',hashMap.get('e')-count*2);
            for (int i = 0; i < count; i++) {
                ans.add(7);
            }
        }
        if (hashMap.containsKey('i')&&hashMap.get('i') > 0) {
            for (int i = 0; i < hashMap.get('i'); i++) {
                ans.add(9);
            }
        }
        ans.sort(Comparator.naturalOrder());
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < ans.size(); i++) {
            sb.append(""+ans.get(i));
        }
        return sb.toString();
    }
}
//leetcode submit region end(Prohibit modification and deletion)
