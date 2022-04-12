1. 如何定义垃圾？
2. Java两种垃圾回收模型：分代模型和分区模型
3. stw：stop-the-world，垃圾回收机制运行时，停止所有业务逻辑
4. Jdk1.8默认垃圾回收机制：Parallel Scavenge （单线程）&& Parallel Old（多线程）
5. 三色标记算法
   1. 白色：所有节点最开始都是白色，表示没有遍历的节点
   2. 灰色：当前节点已经被遍历，但是他的孩子节点还没有被标记
   3. 黑色：当前节点已经被遍历，所有的孩子节点都被标记
6. CMS的bug：

![image-20220107194720727](/Users/gaoyinghao/Library/Application Support/typora-user-images/image-20220107194720727.png)

修复：初步找到目标树之后，再从头搜索一遍可能遗漏的节点

7. G1：同样基于三色标记算法

8. 程序中最难调试的bug：
   1. 野指针
   2. 并发问题
9. 