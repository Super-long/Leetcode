#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_set<int> vis;
    vector<TreeNode*> res;
    void dfs(TreeNode* root, TreeNode* parent, bool flag){
        if(!root) return;
        int temp = parent ? parent->val : -1;
        if(vis.find(root->val) != vis.end()){
            // 这个插入的结点仍可能是要被删除的结点
            if(root->left && vis.find(root->left->val) == vis.end()) {res.push_back(root->left);}
            if(root->right && vis.find(root->right->val) == vis.end()) {res.push_back(root->right);}

            if(flag && parent) parent->left = nullptr;
            else if(parent) parent->right = nullptr;    // 注意判断parent是否为空，因为可能是主节点被删除，而且不能直接return， 因为还需要跑下面的递归
        }
        dfs(root->left, root, true);
        dfs(root->right, root, false);
        return;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto x : to_delete){vis.insert(x);}
        dfs(root, nullptr, true);
        if(vis.find(root->val) == vis.end()) res.push_back(root);
        return res;
    }
};