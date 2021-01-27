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

class Solution {    // 把二叉树以前序转化为链表，前序的非递归写法还是需要注意的，里面压栈的顺序需要注意。
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;

        stack<TreeNode*> stk;
        stk.push(root);
        TreeNode* prev = nullptr;

        while (!stk.empty()){
            auto node = stk.top();
            stk.pop();

            auto left = node->left;
            auto right = node->right;

            if(prev != nullptr) {
                prev->left = nullptr;
                prev->right = node;
            }
            
            if(right != nullptr) {
                stk.push(right);
            }

            if(left != nullptr) {
                stk.push(left);
            }
            prev = node;
        }
        
        return;
    }
};

