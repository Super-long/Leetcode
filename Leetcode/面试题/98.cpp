// 验证二叉搜索树
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution { //递归
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT64_MIN,INT64_MAX);
    }

    bool dfs(TreeNode* root, long long lhs, long long  rhs){
        if(root == nullptr) return true;
        if(root->val <= lhs || root->val >= rhs) return false;
        return dfs(root->left, lhs, root->val) && dfs(root->right,root->val, rhs);
    }
}; */

class Solution { //中序遍历 得到的一定是升序
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> sta;
        long long prev = INT64_MIN;
        while(!sta.empty() || root != nullptr){
            while(root!=nullptr){
                sta.push(root);
                root = root->left;
            }
            root = sta.top();
            sta.pop();
            if(root->val <= prev){
                return false;
            }
            prev = root->val;
            root = root->right;
        }
        return true;
    }
};