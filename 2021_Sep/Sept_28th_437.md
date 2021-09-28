# Sept_28th_437  路径总和 III（中等）

## 题目

给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

## 输出示例

```bash
输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
```

## 解答

定义节点的前缀和为：由根结点到当前结点的路径上所有节点的和。我们利用先序遍历二叉树，记录下根节点 `root` 到当前节点 `p` 的路径上除当前节点以外所有节点的前缀和，在已保存的路径前缀和中查找是否存在前缀和刚好等于当前节点到根节点的前缀和 `curr - targetSum`。

左右子树遍历完成之后，回到当前层，需要把当前节点添加的前缀和去除。避免回溯之后影响上一层。因为思想是前缀和，不属于前缀的，我们就要去掉它。
[code](https://github.com/Songmg-Nwafu/Leetcode/blob/main/2021_Sep/Sep_28th_437.cpp)

```cpp
//
// Created by smg_nwafu on 2021/9/28.
//
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    unordered_map<int, int> prefix;
    int dfs(TreeNode* root, long long curr, int targetSum){
        if (root == nullptr){
            return 0;
        }

        int res = 0;
        curr += root -> val;

        if (prefix.count(curr - targetSum)){
            res += prefix[curr - targetSum];
        }

				// 将当前前缀和记录下来
        prefix[curr]++;

        res += dfs(root -> left, curr, targetSum);
        res += dfs(root -> right, curr, targetSum);
        // 回溯，恢复状态
				prefix[curr]--;


        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
```

## 复杂度分析

- 时间复杂度：O(N)，其中 N*N* 为二叉树中节点的个数。利用前缀和只需遍历一次二叉树即可。
- 空间复杂度：O(N)。