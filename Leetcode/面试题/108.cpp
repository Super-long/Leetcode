// 将有序数组转换为二叉搜索树
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs(vector<int>& nums, int lhs, int rhs){
        if(lhs > rhs) return nullptr;
        int mid = (lhs + rhs)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left  = dfs(nums, lhs, mid - 1);
        root->right = dfs(nums, mid + 1, rhs);
        return root; 
    }
};