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
private:
    unordered_map<int, int> vis;
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pre_lhs, int pre_rhs, int in_lhs, int in_rhs){
        if(pre_lhs > pre_rhs) return nullptr;
        
        int rootNumber = preorder[pre_lhs];
        auto root = new TreeNode(rootNumber);
        int index = vis[rootNumber];

        int len = index - in_lhs;
        root->left = dfs(preorder, inorder, pre_lhs + 1, pre_lhs + len, in_lhs, index - 1);
        root->right = dfs(preorder, inorder, pre_lhs + len + 1, pre_rhs, index + 1, in_rhs);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i){
            vis[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, inorder.size() - 1, 0, inorder.size() - 1);
    }
};