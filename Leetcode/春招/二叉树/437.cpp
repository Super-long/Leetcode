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
    int res = 0;
    int all;
    void check(int sum){
        if(vis.find(sum - all) != vis.end()){
            res += vis[sum - all];
        }
    }

    void dfs(TreeNode* root, int sum){
        if(!root) return;
        check(sum + root->val);
        vis[sum + root->val]++;
        dfs(root->left, sum + root->val);
        dfs(root->right, sum + root->val);
        vis[sum + root->val]--;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        all = sum;
        vis[0]++;
        dfs(root, 0);
        return res;
    }
};