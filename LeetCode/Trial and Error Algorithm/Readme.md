<h2>Trial and Error Algorithm 试错算法</h2>

LeetCode

[378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/)

[668. Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/)

[719. Find K-th Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/)

[786. K-th Smallest Prime Fraction](https://leetcode.com/problems/k-th-smallest-prime-fraction/description/)

第一步：构建一个可能解<br>
第二步：验证这个解是否符合我们的要求<br>
第三步：如果符合，就接受它；不符合，就放弃它，重新回到第一步

但是有两个前提条件需要满足

+ 我们有有效的验证算法来检验第二步是否正确
+ 由所有候选解形成的搜索空间很小，或者如果它很大，我们有有效的方法来遍历（或搜索）该空间。

<hr>

<h3>以LeetCode 719为例</h3>

1. 构建一个可能解：要求我们输出第K个最小的对距离，这不过是一个非负整数（因为输入数组nums是一个整数数组，而对距离是绝对值）。因此，我们的候选解决方案也应该是非负整数。

2. 由所有候选解决方案形成的搜索空间：设`min`和`max`为输入数组`nums`中的`最小`和`最大`数，那么`d = max - min`，所以合理解的搜索空间为`[0, d]`

3. 验证给定的候选解：（这道题的核心）
  + Naive方法：算出所有对距离并按升序对它们进行排序，则第`K`个最小对距离将是索引`K-1`处的距离（但是会出现`TLE`或者`MLE`的情况）
  + **第二种定义kth对最短距离的方法：给定一个整数`num`，设`count(num)`表示不大于`num`的对距离数，那么第K个最小对距离将是使`count（num）> = K`满足的最小的整数num**

4. 计算不超过给定整数的对距离数
  + 首先，操作如果另外开一个数组则就是`O(N^2)`复杂度，算法毫无意义，但是原始数组又是无序的，所以无法进行操作。所以第一步是使得数组有序
  + 定义`d_ij`是数组`a[i]`与`a[j]`之间的距离（设`j > i`则有`d_ij = a[j] - a[i]`）
  + 如果保持`i`固定，则`d_ij <= num`等价于`a[j] <= a[i] + num`（右边为定值）
  + 这表明我们至少可以用二分搜索找到最小索引`j`，使得每个索引`i`的`a[j] > a[i] + num`，然后索引`i`的计数为`j - i - 1`，而且总的来说，有一个`O(NlogN)`的验证算法
  + 如果我们使用双指针的方法，计数操作可以在线性时间内完成：假设我们有两个起始索引`i1`和`i2`，`i1 < i2`，让`j1`和`j2`成为最小的索引满足`a[j1] > a[i1] + num`和`a[j2] > a[i2] + num`，那么`j2 >= j1`必须为`true`。

5. 如何有效地遍历（或搜索）搜索空间
  + Naive方法：从`0`到`d`依次遍历选择出第一个`num`，使得`count(num) >= K`，复杂度为`O(nd)`
  + 对于非递减属性，我们可以使用二分搜索，而且有`num1`和`num2`，如果`num1 < num2`则有`count(num1) <= count(num2)`
     + 设`[l, r]`为当前的搜索空间，`l = 0`，`r = d`
     + 若`l < r`，计算得`m = (l + r) / 2`，评估`count(m)`
     + 如果count(m) < K，放弃左半部分并设置`l = m + 1`；否则放弃右半部分设置并`r = m`

6. 完成代码

时间复杂度为`O(Nlogd + NlogN)`空间复杂度为`O(N)`

```cpp
class Solution{
public:
    int smallestDistancePair(vector<int> &nums, int k){
        sort(nums.begin(), nums.end());
        int d = *--nums.end() - *nums.begin();
        int l = 0, r = d;
        
        for (int count = 0; l < r; count = 0)
        {
            int m = (l + r) / 2;
            for (int i = 0, j = 0; i < nums.size(); i++)
            {
                while (j < nums.size() && nums[j] <= nums[i] + m)
                    j++;
                count += j - i - 1;
            }
            
            if (count < k)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};
```

