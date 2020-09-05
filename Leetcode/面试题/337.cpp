#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 树形dp
    pair<int,int> dfs(TreeNode* root){
        if(root == nullptr){
            return {};
        }
        pair<int, int> f = dfs(root->left);
        pair<int, int> g = dfs(root->right);
        pair<int, int> res;
        res.first = root->val + f.second + g.second;   // 使用这一点
        res.second = max(f.first,f.second) + max(g.first, g.second);
        return res; // RVO
    }

public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};