# 排序算法   

**实现的主要算法如下**    
1. 冒泡排序：`algorithms/sort/bubble_sort`   
2. 插入排序：`algorithms/sort/insert_sort`   
3. 归并排序：`algorithms/sort/merge_sort`   
4. 快速排序：`algorithms/sort/quick_sort`   
5. 堆排序：`algorithms/heap`   

**如何分析一个排序算法？**
- 执行效率
    - 最好情况、最坏情况、平均情况时间复杂度
    - 时间复杂度的系数、常数 、低阶
    - 比较次数和交换（或移动）次数
- 内存消耗  
    - 原地排序还是需要额外空间   
- 稳定性  
    - 值相等的两个元素排序之后，相对位置不变
- 冒泡排序相比插入排序实际性能更慢一点，涉及到操作更多   
- 冒泡、插入、选择排序都有一个共同点，将待排序数列分为已排序和未排序两部分。在未排序的部分中查找一个最值，放到已排序数列的恰当位置。

| 算法 | 时间复杂度(min、max、avg) | 空间复杂度 | 稳定性 |
| ------ | ------ | ------ | ------ |
| 冒泡 | O(n)、O(n^2)、O(n^2) | O(1) | 稳定 |
| 插入 | O(n)、O(n^2)、O(n^2) | O(1) | 稳定 |
| 选择 | O(n)、O(n^2)、O(n^2) | O(1) | 不稳定 |
| 快排 | O(n)、O(n^2)、O(nlogn) | O(1) | 不稳定|
| 归并 | O(nlogn)、O(nlogn)、O(nlogn) | O(nlogn) | 稳定|
| 堆排 | O(nlogn)、O(nlogn)、O(nlogn) | O(1) | 不稳定|

**参考**
https://time.geekbang.org/column/article/41802   