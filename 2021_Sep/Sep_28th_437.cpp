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

        prefix[curr]++;
        res += dfs(root -> left, curr, targetSum);
        res += dfs(root -> right, curr, targetSum);
        prefix[curr]--;

        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};