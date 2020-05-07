// 另一颗树的子树
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
    bool check(TreeNode *o, TreeNode *t) {
        if (!o && !t) return true;
        if ((o && !t) || (!o && t) || (o->val != t->val)) return false;
        return check(o->left, t->left) && check(o->right, t->right);
    }

    bool dfs(TreeNode *o, TreeNode *t) {
        if (!o) return false;
        return check(o, t) || dfs(o->left, t) || dfs(o->right, t);
    }

    bool isSubtree(TreeNode *s, TreeNode *t) {
        return dfs(s, t);
    }
};