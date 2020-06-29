// 二叉树中的最大路径和
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int res = -0x3f3f3f3f;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int lhs = dfs(root->left);
        int rhs = dfs(root->right);
        int Max = max(max(max(lhs, rhs), rhs + lhs) + root->val, root->val);
        if(Max > res){
            res = Max;
        }
        return max(max(lhs, rhs) + root->val, root->val);
    }
};