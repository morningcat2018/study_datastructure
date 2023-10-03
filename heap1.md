

## 优先队列

概念
- 普通队列:先进先出
- 优先队列:出队顺序和入队顺序无关,和优先级相关

应用场景
- 操作系统任务管理:动态选择优先级最高的任务执行
- 在 N 个元素中选出前 M 个元素
    - 整体排序 NlogN
    - 使用优先队列 NlogM


![image.png](https://p1-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/9f213f6f9189444a905c00e66ab1d00e~tplv-k3u1fbpfcp-jj-mark:0:0:0:0:q75.image#?w=2474&h=1364&s=498867&e=png&b=fefdff)

- 使用数组实现优先队列 时间复杂度: O(n^2)
- 使用堆实现优先队列 时间复杂度: O(nlgn)


## 堆的基本存储

#### 最大二叉堆

- 堆中某个节点的值总是不大于其父节点的值
- 堆保持是一棵`完全二叉树`
    - 除了最后一层外,其他层的节点必须是最大节点数
    - 最后一层要优先集中在左侧

![image.png](https://p6-juejin.byteimg.com/tos-cn-i-k3u1fbpfcp/cf95a7e5bb7c4bd98d96ef82c1038a5a~tplv-k3u1fbpfcp-jj-mark:0:0:0:0:q75.image#?w=1734&h=1016&s=548666&e=png&b=fdfcfe)


#### 用数组实现最大二叉堆

max_heap.h

max_heap_test.cpp


