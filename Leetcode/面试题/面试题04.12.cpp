// 求和路径
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { // 由上向下的遍历方式确实很巧妙，开始一直思考从下到上
unordered_map<int, int> mp;
int res;
int sum;
public:
    int pathSum(TreeNode* root, int sum) {
        mp.clear();
        res = 0;
        this->sum = sum;
        mp[0] = 1;  // 很重要 

        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int temp){
        if(!root) return;

        if(mp.find(temp + root->val - sum) != mp.end()) res += mp[temp + root->val - sum];
        ++mp[temp+root->val];
        // if(temp + root->val == sum) ++res;
        dfs(root->left, temp + root->val);
        dfs(root->right, temp + root->val);
        --mp[temp+root->val];
    }
};