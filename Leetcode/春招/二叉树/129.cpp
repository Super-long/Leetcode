#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
int res = 0;
void dfs(TreeNode* root, int flag){
    if(!root) return;
    flag += root->val;
    if(!root->left && !root->right){
        res += flag;
        return;
    }
    dfs(root->left, flag*10);
    dfs(root->right, flag*10);
    return;
}
public:
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return res;
    }
};