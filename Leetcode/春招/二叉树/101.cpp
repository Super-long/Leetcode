#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 判断二叉树是否是镜像对称的
private:
    bool dfs(TreeNode *lNode, TreeNode *rNode) {
        if(!lNode && !rNode) return true;
        if(!lNode || !rNode || (lNode->val != rNode->val)){
            return false;
        }
        return dfs(lNode->right, rNode->left) && dfs(lNode->left, rNode->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left, root->right);
    }
};