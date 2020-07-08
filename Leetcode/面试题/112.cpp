// 路径总和
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution { // 思路有问题，叶子节点是没有子节点的节点
private:
    bool result;
    int sum;
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        this->sum = sum;
        result = false;
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode* root, int res){
        if(!root){
            if(res == sum){
                result = true;
            }
            return;
        }
        dfs(root->left, res + root->val);
        dfs(root->right, res + root->val);
        return;
    }
}; */

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};
