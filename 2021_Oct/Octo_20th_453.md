## 题目

给你一个长度为 n 的整数数组，每次操作将会使 n - 1 个元素增加 1 。返回让数组所有元素相等的最小操作次数。

## 输出示例

```cpp
输入：nums = [1,2,3]
输出：3
解释：
只需要3次操作（注意每次操作会增加两个元素的值）：
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
```
[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Oct/Oct_20th_453.cpp)
## 解答

每次操作将会使 n - 1 个元素增加 1 ，相当于每次操作会使  1  个元素减少 1 。这样只需要找到最小的元素就可以了。

```cpp
class Solution{
public:
    int minMoves(vector<int>& nums){
        int minNum = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (auto num: nums){
            res += num - minNum;
        }
        return res;
    }
};
```

## 复杂度分析

- 时间复杂度：*O*(*n*)，其中 *n* 为数组中的元素数量。我们需要一次遍历求出最小值，一次遍历计算操作次数。
- 空间复杂度：*O*(1)。