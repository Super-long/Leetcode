#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {    // 自顶向下
int dfs(TreeNode *root){
    if(!root) return 0;
    
    auto lhs = dfs(root->left);
    auto rhs = dfs(root->right);

    return max(lhs, rhs) + 1; 
}
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return abs(dfs(root->left) - dfs(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};

class Solution {    // 自底向上,显然这样会快很多；唯一的缺点就是这里的-1是魔法数字
int dfs(TreeNode *root){
    if(!root) return 0;
    
    auto lhs = dfs(root->left);
    auto rhs = dfs(root->right);

    if(lhs == -1 || rhs == -1 || abs(lhs - rhs) > 1) return -1;

    return max(lhs, rhs) + 1; 
}
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return dfs(root) != -1;
    }
};
