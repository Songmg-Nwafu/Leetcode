# Sept_22th_725  分隔链表（中等）
## 题目

给你一个头结点为 head 的单链表和一个整数 k ，请你设计一个算法将链表分隔为 k 个连续的部分。

每部分的长度应该尽可能的相等：任意两部分的长度差距不能超过 1 。这可能会导致有些部分为 null 。

这 k 个部分应该按照在链表中出现的顺序排列，并且排在前面的部分的长度应该大于或等于排在后面的长度。

返回一个由上述 k 部分组成的数组。

## 输出示例

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4d65caa9-07cc-4b66-9161-0d9f129b9b21/Untitled.png)

```bash
输入：head = [1,2,3,4,5,6,7,8,9,10], k = 3
输出：[[1,2,3,4],[5,6,7],[8,9,10]]
解释：
输入被分成了几个连续的部分，并且每部分的长度相差不超过 1 。前面部分的长度大于等于后面部分的长度。
```

## 解答

题目要求将给定的链表分隔成 k 个连续的部分。由于分隔成的每个部分的长度和原始链表的长度有关，因此需要首先遍历链表，得到链表的长度 n。

$quotient = \lfloor \frac nk \rfloor$  ,  $remainder = n\;mod \; k$ ;则在分隔成的 k 个部分中，前 `remainder` 个部分的长度各为 `quotient+1`，其余每个部分的长度各为 `quotient`。

```bash
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int list_length = 0;
        ListNode* tmp = head;
        while (tmp != nullptr){
            list_length++;
            tmp = tmp -> next;
        }
        int n = list_length / k, re = list_length % k;
        vector<ListNode*> part(k, nullptr);
        ListNode* cur = head;
        for (int i = 0; i < k && cur != nullptr; ++i) {
            part[i] = cur;
            int part_size = n + (i < re ? 1 : 0);
            for (int j = 1; j < part_size; ++j) {
                cur = cur -> next;
            }
            ListNode* ptr = cur -> next;
            cur -> next = nullptr;
            cur = ptr;
        }

        return part;
    }
};
```
[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Sep/Sep_22th_725.cpp)

## 复杂度分析

- 时间复杂度：O(n)，其中 n 是链表的长度。需要遍历链表两次，得到链表的长度和分隔链表。
- 空间复杂度：O(1)。只使用了常量的额外空间，注意返回值不计入空间复杂度。