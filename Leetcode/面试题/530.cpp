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
    int res;
    int prev;
public:
    int getMinimumDifference(TreeNode* root) {
        res = INT32_MAX;
        prev = -1;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        if(prev >= 0){ // root非树根
            auto temp = root->val - prev;   // 不需要求绝对值 
            if(temp < res) res = temp;
        }
        prev = root->val;
        dfs(root->right);
    }
};