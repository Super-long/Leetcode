// 二叉树的最近公共祖先
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { //递归
private:
    TreeNode* res;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);

        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            res = root; //只有遇到深度最深的节点的时候才会更新答案 那时才满足上述条件 即两个true
        } 

        return lson || rson || (root->val == p->val || root->val == p->val);
    } 

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};