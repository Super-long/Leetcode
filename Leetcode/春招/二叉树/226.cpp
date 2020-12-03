#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 反转二叉树
private:
    void dfs(TreeNode* root){
        if(!root) return;
        auto left = root->left;
        auto right = root->right;
        dfs(left);
        dfs(right);
        root->left = right;
        root->right = left;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }
};