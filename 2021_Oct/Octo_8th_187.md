# Octo_8th_187 重复的DNA序列

## 题目

所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

## 输出示例

```
输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
输出：["AAAAACCCCC","CCCCCAAAAA"]
```

## 解答

由于 ss 中只含有 44 种字符，我们可以将每个字符用 22 个比特表示，即：

- A 表示为二进制 00；
- C 表示为二进制 01；
- G 表示为二进制 10；
- T 表示为二进制  11。

如此一来，一个长为 10 的字符串就可以用 20 个比特表示，而一个 int 整数有 32 个比特，足够容纳该字符串，因此我们可以将 s 的每个长为 10 的子串用一个int 整数表示（只用低 20 位）。

注意到上述字符串到整数的映射是一一映射，每个整数都对应着一个唯一的字符串，因此我们可以将方法一中的哈希表改为存储每个长为 10 的子串的整数表示。

设当前滑动窗口对应的整数表示为 x，当我们要计算下一个子串时，就将滑动窗口向右移动一位，此时会有一个新的字符进入窗口，以及窗口最左边的字符离开窗口，这些操作对应的位运算，按计算顺序表示如下：

滑动窗口向右移动一位：`x = x << 2`，由于每个字符用 2 个比特表示，所以要左移 2 位；
一个新的字符`ch` 进入窗口：`x = x | bin[ch]`，这里 `bin[ch]` 为字符 `ch` 的对应二进制；
窗口最左边的字符离开窗口：`x = x & ((1 << 20) - 1)`，由于我们只考虑 x 的低 20 位比特，需要将其余位置零，即与上 `(1 << 20) - 1`。
将这三步合并，就可以用 O(1)的时间计算出下一个子串的整数表示，即 `x = ((x << 2) | bin[ch]) & ((1 << 20) - 1)`。
[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Oct/Oct_8th_187.cpp)

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'T', 1}, {'C', 2}, {'G', 3}};
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int n = s.length();
        if(n <= L)
            return ans;

        //初始化第一个滑窗的值
        int x = 0;
        for (int i = 0; i < L - 1; ++i) {
            x = (x << 2) | bin[s[i]];
        }

        //将每个滑窗的值存储到cnt中
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n - L; ++i) {
            x = ((x << 2) | bin[s[i + L - 1]]) & ((1 << L * 2) - 1);
            ++cnt[x];
            if (cnt[x] == 2 )
                ans.push_back(s.substr(i, L));
        }

        return ans;
    }
};
```

## 复杂度分析

- 时间复杂度：*O*(*N*)，其中 *N* 是字符串 *s* 的长度。
- 空间复杂度：*O*(*N*)。