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
    int sum  = 0x3f3f3f3f;
    bool dfs(TreeNode* root, int depth){
        if(!root) return false;
        bool lhs = dfs(root->left, depth + 1);
        bool rhs = dfs(root->right, depth + 1);
        if(!lhs && !rhs){
            sum = min(sum, depth);
        }
        return true;
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 1);
        return sum;
    }
};