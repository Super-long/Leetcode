#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int ret;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ret = 1;
        dfs(root); //返回值为最大的子树的深度(最长路径结点数)
        return ret - 1;
    }

    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        ret = max(L + R +1 , ret);
        return max(L, R)+1;
    }
};