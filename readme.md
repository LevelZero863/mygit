##### 2022-6-9:

数学基础：辗转相除求最大公因数

```c++
int gcd(int a ,int b) {
  return b==0?a:gcd(b,a%b);
}
```

最小公倍数：a*b/(最大公因数)

埃氏筛法求小于n的所有质数：基本思想是，遍历1->n，将当前数字m的倍数标记，最后再遍历一次，所有没被标记的数字都是质数。

单调栈的心得：https://zhuanlan.zhihu.com/p/523444328

##### 2022-6-6:

- 指针的使用需要初始化，否则会产生未定义行为

  ```c++
  int* p;//error
  int* q;
  q=existInt;//existInt是一个存在的指针，此时意图给q赋值，error
  int* t = NULL;//true
  int* tt = new int(9);//true;
  int8 ttt = existInt;//true;
  ```

- NULL与nullptr的区别

​		NULL是C语言中定义的宏：#define NULL ((void*) 0)

​		使用NULL容易产生二义性问题，NULL可能会被解析成指针类型或者非指针类型

​		而nullptr是C++11标准引入的，它只会被解析成指针类型

##### 2022-5-4:

背包问题：

- 0-1背包问题
- 无界背包问题/完全背包问题

0-1背包：

- 二维数组：时空复杂度都是O(NW)

  ```c++
  //dp[i][j]-->前i件物品体积不超过j的情况下，value的最大值
  dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
  ```

- 一维数组：时间复杂度O(NW),空间复杂度O(W)

  ```c++
  //因为当前排i只取决于上一排i-1的信息，所以可以用一维数组表示
  dp[j] = max(dp[j],dp[j-w]+v);
  ```


完全背包：

- 二维数组：时空复杂度都是O(NW)

  ```c++
  //max中的两个变量，如果选取了前者，表示第i个不能加入背包；如果选取了后者，表示可以加入一个i。
  dp[i][j] = max(dp[i-1][j],dp[i][j-w]+v);
  ```

- 一维数组：时间复杂度O(NW),空间复杂度O(W)

  ```c++
  d[j] = max(dp[j],dp[j-w]+v);
  ```

##### 2022-4-19

四平方和定理：证明了任意一个正整数都可以被表示为至多四个正整数的平方和。

![image-20220419171124685](/Users/gaoyinghao/Library/Application Support/typora-user-images/image-20220419171124685.png)

##### 2022-4-16

并查集？

##### 2022-4-15

关于二分查找：[https://zhuanlan.zhihu.com/p/79553968]()

##### 2022-4-13

1. 牛顿迭代法：是一种可以用来快速求解函数零点的方法。

![image-20220413153847975](/Users/gaoyinghao/Library/Application Support/typora-user-images/image-20220413153847975.png)

2. ![image-20220413141228494](/Users/gaoyinghao/Library/Application Support/typora-user-images/image-20220413141228494.png)

##### 2022-4-12

```C++
unordered_map <char, int> ori, cnt;
for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
```

这段代码，指针p的first指向char位置，second指向int位置

**2022-1-14**

优先队列的C++实现与应用问题

总结于该文章

> [Lambda表达式的简单使用和C++Priority_queue（优先队列）的使用总结 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/459445739)

##### 2021-12-6

1. 快速幂：指的是降低复杂度求幂的算法。有递归和迭代两种写法。

​			递归容易理解，比如求x的77次幂，可以先递归的求解x的77/2向下取整次方，最后将结果根据77是奇数还是偶数，进行平再乘x或者进行平方。

​			迭代主要是利用二进制，也就是对77求二进制，将二进制位对应的位的值作为x的次方数，将所有的x的次方数乘起来就是结果。

2. ![image-20211206174645658](/Users/gaoyinghao/Library/Application Support/typora-user-images/image-20211206174645658.png)

3. 372题解？

##### 2021-12-2

TreeMap的效率？

##### 2021-11-16

扫描线问题：扫描线一般运用在图形上面，它和它的字面意思十分相似，就是一条线在整个图上扫来扫去，它一般被用来解决图形面积，周长等问题。

##### 2021-10-28

判断一个数n是否为2的幂：用位运算 n & （n-1）== 0判断。如果等于0，则n为2的幂

##### 2021-10-27

挖个坑：单调栈

1. 单调栈：
   1. 什么是单调栈：单调栈分为单调递增栈和单调递减栈。单调递增栈是说从栈底到栈顶数据是从大到小的；单调递减栈是说从栈底到栈顶数据是从小到大的。
   2. 模拟单调栈的push和pop：现在有一组数10，3，7，4，12。从左到右依次入栈，则如果**栈为空**或**入栈元素值小于栈顶元素值**，则入栈；否则，如果入栈则会破坏栈的单调性，则需要把比入栈元素小的元素全部出栈。单调递减的栈反之。
   3. 解决什么类型的问题：主要用于解决NGE问题(Next Greater Element)，也就是，对序列中的每个元素，找到下一个（上一个）比它大（小）的元素。

##### 2021-10-22

摩尔投票法

**原理**：考虑最简单的情况，寻找长度为n的序列中出现次数超过n/2的元素，那么满足这样要求的元素只有一个。在此基础上，如果是寻找出现次数超过n/3的元素，那么满足这样要求的元素只有两个，以此类推。

**代码实现**：从代码实现上说，以寻找出现次数超过n/3的元素为例，首先遍历整个序列，同时检查当前元素是否与假定的两个元素（最开始假定前两个元素）不同，如果不同，则将这两个元素的出现次数减1，如果减到0，则假定下一个遍历到的元素为假定答案。最后得到两个可能答案（答案一定在这两个里面，在这里面的不一定是答案），再重新遍历一边序列，检查这两个元素出现的次数，如果超过n/3则是答案。

##### 2021-10-19

字典树

1. 什么是字典树？

   字典树（前缀树）是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。

2. 用于解决什么问题？

   1. 串的快速检索问题：给出N个单词组成的熟词表，以及一篇全用小写英文书写的文章，请你按最早出现的顺序写出所有不再熟词表中的生词。在这道题中，我们可以用字典树，先把熟词建一棵树，然后读入文章进行比较。
   2. 串排序问题：给定N个互不相同的仅由一个单词构成的英文名，让你将他们按字典序从小到大输出用字典树进行排序，采用数组的方式创建字典树，这棵树的每个结点的所有儿子很显然地按照其字母大小排序。对这棵树进行先序遍历即可。
   3. 最长公共前缀问题：对所有串建立字典树，对于两个串的最长公共前缀的长度即他们所在的结点的公共祖先个数，于是，问题就转化为最近公共祖先问题。

3. 图形化结构？

   ![image-20211019154725728](/Users/gaoyinghao/Library/Application Support/typora-user-images/image-20211019154725728.png)

4. 数据结构

   ```java
   class Trie {
       private Trie[] children;
       private boolean isEnd;
   
       public Trie() {
           children = new Trie[26];
           isEnd = false;
       }
       
       public void insert(String word) {
           Trie node = this;
           for (int i = 0; i < word.length(); i++) {
               char ch = word.charAt(i);
               int index = ch - 'a';
               if (node.children[index] == null) {
                   node.children[index] = new Trie();
               }
               node = node.children[index];
           }
           node.isEnd = true;
       }
   
       public Trie[] getChildren() {
           return children;
       }
   
       public boolean isEnd() {
           return isEnd;
       }
   }
   ```

   

##### 2021-10-18

位运算还是不熟练啊

##### 2021-10-12

关于位运算：

1. 位取反（~）:0变1，1变0

2. 位与（&）：eg.125&7，两位同时为1才为1，否则结果为0

3. 位或（｜）：eg.125｜7两位同时为0，结果才为0，否则结果为1

4. 异或（^）：两位相同取0，不同取1

   编程中的作用：交换两个数

   ```java
   public void Swap(int  &a,  int  &b){  
     if  (a  !=  b){  
       a  ^=  b; //a=a^b
       b  ^=  a; //b=b^(a^b) = (b^b)^a = a 
       a  ^=  b; //a=(a^b)^a = (a^a)^b = b
           }  
   }
   ```

   

5. 右移（>>）:将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。 Eg. 125>>3 = 15 等价于125除以2的3次方的商

6. 左移（<<）:将一个运算对象的各二进制位全部左移若干位，左边的二进制位丢弃，右边补0。eg. 125<<3 = 1110 1000 = -24(八位) = 1000(十六位)。等价于125*2的3次方（若左移时舍弃的高位不包含1）

7. 无符号右移（>>>）:始终补-，不考虑正负数

##### 2021-10-11

每日一题打卡，递归训练

##### 2021-10-9

TreeMap

1. 什么是TreeMap？与HashMap相比，TreeMap是一个能比较元素大小的Map集合，会对传入的key进行大小排序。其中，可以使用元素的自然排序，也可以使用集合中自定义的比较器来进行排序。

2. 基本操作

   ```java
   //创建TreeMap对象
   TreeMap<String,Integer> treeMap = new TreeMap<String,Integer>();
   //新增元素
   treeMap.put("hello",1);
   //遍历元素
   Set<Map.Entry<String,Integer>> entrySet = treeMap.entrySet();
   for(Map.Entry<String,Integer> entry : entrySet){
     String key = entry.getKey();
     Integer Value = entry.getValue();
   } 
   //获取所有的key：
   Set<String> keySet = treeMap.keySet();        for(String strKey:keySet){            			 	      System.out.println("TreeMap集合中的key:"+strKey);
   }
   //获取所有的value:
   Collection<Integer> valueList = treeMap.values();        for(Integer intValue:valueList){
      System.out.println("TreeMap集合中的value:" + intValue);
   }
   ```

   

##### 2021-10-8

每日一题还是哈希表的应用

##### 2021-10-5

国庆节首学：

关于Iterator 类：主要用于容器的遍历等操作

1. 使用

   ```java
   List list = new ArrayList<Integer>{};
   list.add(12);
   Iterator iterator = list.iterator();
   ```

   

##### 2021-9-29

java中的异或运算符号：^

1. 任何数和 00 做异或运算，结果仍然是原来的数，即 a⊕0=a*a*⊕0=*a*。
2. 任何数和其自身做异或运算，结果是 00，即 a⊕a=0*a*⊕*a*=0。
3. 异或运算满足交换律和结合律

HashMap实际操作：

```java
//初始化
Map<Integer,Integer> hashMap = new HashMap<>();
//添加值，num是key，getOrDefault(num,0)取key为num的value，如若没有，则取默认值0
hashMap.put(num,hashMap.getOrDefault(num,0));
//遍历
for(Map.Entry<Integer,Integer> entry : hashMap.entrySet()){
  int num = entry.getKey();
  int occ = entry.getValue();
}
```



##### 2021-9-14

1.哈希表常用类及其用法

- HashMap：线程不安全，效率最高。Map<Object,Object> aMap = new HashMap<>(16);
- HashTable:线程安全，不支持存放键为null的情况。通常不适用HashTable，而是使用ConcurrentHashMap，因为效率更高。
- HashSet：与HashMap的区别是，HashSet存放的是单个值，而且不能重复

2.java比较器：Comparable接口与Comparator接口

| 类名       |                                                              |                                                              |            |
| ---------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------- |
| Comparable | 重写comparaTo（obj）的规则：如果当前对象this大于形参对象obj，则返回正整数；如果小于，则返回负整数；如果等于，则返回零 | 自然排序：对于自定义类来说，如果需要排序，我们可以让自定义类实现Comparable接口（implements），重写comparaTo（obj），在comparaTo（obj）方法中指明如何排序 | “一劳永逸” |
| Comparator | 重写compara（object o1，object o2）方法，比较o1和o2的大小。如果返回正整数，则表示o1大于o2；返回零，表示相等；返回负整数，表示o1小于o2 |                                                              | “临时性”   |



##### 2021-9-9

股票买卖问题。动态规划算法：两个状态，一个是第i天手里有股票，一个是没有股票。如果有股票，那么有两种情况，一种是前一天就有（也就是说不是今天买的），一种是今天刚买的，因此比较前一天有股票状态时的收益和前一天没有股票的收益减去今天股票的价格，得到更大的值来更新第i天手里有股票的收益。如果没有股票，那么也有两种情况，一种是前一天就没有股票了，一种是今天刚把股票卖掉，因此比较前一天没有股票时的收益和前一天有股票时的收益加上今天股票的价格。

##### 2021-8-4

单调栈：

##### 2021-8-3

写了一下午回溯medium，都是一遍过，好像懂一点回溯了……

##### 2021-8-1

备忘录：复习一下Java Comparator及其他的用于排序的借口

##### 2021-7-31

没时间写了。。。

##### 2021-7-28

一个回溯一个Hard，回溯勉强通过，但是效率很低，不过好在对回溯法有了基本的认识。hard是之前见过的，并且还有点印象，但是
忽略了最重要的一点，答案一定在区间【1，N】上，所以花了很长时间没有做出，并且最后的bug是真的恶心，怎么改都越界，还是在回家
路上复盘出来的。

##### 2021-7-22

又一次暴力写了一个题，不出意外还是超时了。不过学到了双指针法。下午基本比较顺利，今天主要是接触了双指针法，在多层循环中可以降低一个次方的复杂度。再就是二分查找，原地数组操作。

##### 2021-7-20

从昨天到现在做了三个题，easy过了，hard不会做，看了答案也一知半解，medium用动态规划要么内存超了要么时间超了，太难了...
