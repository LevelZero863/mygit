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
