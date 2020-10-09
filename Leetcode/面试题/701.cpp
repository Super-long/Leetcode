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

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            auto node = new TreeNode(val);
            root = node;
            return root;
        }
        dfs(root, val);
        return root;
    }

    bool dfs(TreeNode* root, int val){
        // 题目保证val和书中的值不相等
        if(root == nullptr){
            return true;    // 表示这个地方可以进行插入
        }
        if(val > root->val){
            if(dfs(root->right, val)){
                auto node = new TreeNode(val);
                root->right = node;
            }
        } else {
            if(dfs(root->left, val)){
                auto node = new TreeNode(val);
                root->left = node;
            }
        }
        return false;
    }
};