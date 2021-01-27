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

class Solution {    // 非递归中序遍历二叉树需要多刷，容易突然推不出来；这题是我最讨厌的题之一
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return{};
        stack<TreeNode*> stk;
        vector<int> res;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};