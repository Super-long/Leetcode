#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return{};
        stack<TreeNode*> que;
        que.push(root);
        vector<int> res;
        while(!que.empty()){
            TreeNode* Top = que.top();
            que.pop();
            while(Top->left){
                que.push(Top->left);
                Top = Top->left;
            }
            res.push_back(Top->val);
            if(Top->right){
                que.push(Top->right);
            }
        }
        return res;
    }
}; */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return{};
        vector<int> res;
        stack<TreeNode*> stk;
        stk.push(root);
        while(root != nullptr || !stk.empty()){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);   // 只有由节点存在的时候才会while左子树
            root = root->right;
        }
        return res;
    }
};
