# Sept_25th_583  两个字符串的删除操作（中等）
## 题目

给定两个单词 word1 和 word2，找到使得 word1 和 word2 相同所需的最小步数，每步可以删除任意一个字符串中的一个字符。

## 输出示例

```jsx
输入: "sea", "eat"
输出: 2
解释: 第一步将"sea"变为"ea"，第二步将"eat"变为"ea"
```

## 解答

利用动态规划算法求出两个字符串的最长公共子序列就可以了。

$de = length1 + length2 - 2 * lcs$
[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Sep/Sep_25th_583.cpp)
```cpp

class Solution{
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        vector<vector<int>> dp(size1 + 1,vector<int>(size2 + 1));

        for (int i = 1; i <= size1; ++i) {
            char c1 = word1[i - 1];
            for (int j = 1; j <= size2; ++j) {
                char c2 = word2[j - 1];
                if (c1 == c2){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return size1 + size2 - 2 * dp[size1][size2];
    }
};
```

## 复杂度分析

- 时间复杂度：O(mn)，其中 m 和 n 分别是字符串 word1和 word2的长度。二维数组 dp 有 m+1 行和 n+1 列，需要对 dp 中的每个元素进行计算。
- 空间复杂度：O(mn)，其中 m 和 n 分别是字符串 word1和 word2的长度。创建了 m+1 行 n+1列的二维数组 dp。