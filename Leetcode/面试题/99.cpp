// 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* x = nullptr;
        TreeNode* y = nullptr;
        TreeNode* pred = nullptr;
        while(!stk.empty() || root != nullptr){
            while(root != nullptr){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(pred != nullptr && root->val < pred->val){
                y = root;
                if(x == nullptr){   // 这个条件只会被触发一次
                    x = pred;
                }else break;
            }
            pred = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};