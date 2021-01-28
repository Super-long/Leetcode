#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 在二叉搜索树上查找最近公共祖先，这就比较简单，遍历一次或者两次都可以 //对应的可以看一看LCA,236
class Solution {
private:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        if(root->val > p->val && root->val > q->val) return dfs(root->left, p, q);
        else if(root->val < p->val && root->val < q->val) return dfs(root->right, p, q);
        else if(root->val <= q->val && root->val >= p->val) return root;
        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p->val > q->val) swap(p, q);
        return dfs(root, p, q);
    }
};