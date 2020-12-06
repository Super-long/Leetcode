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
    int value = 0;
    void dfs(TreeNode *root, bool LeftOrRight){ // true代表left，false代表right
        if(root == nullptr) return;

        if(LeftOrRight && root->left == nullptr && root->right == nullptr){
            value += root->val;
            return;
        }

        dfs(root->left, true);
        dfs(root->right, false);
        
        return;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root, false);
        return value;
    }
};