// 分裂二叉树的最大乘积
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 骗时间老手了
/* static auto _ = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}(); */

class Solution {
private:
    int sum;
    int best;
    void dfs(TreeNode* root){
        if(!root) return;
        sum += root->val;
        dfs(root->left);
        dfs(root->right);
        return;
    }

    int solve(TreeNode* root){
        if(!root) return 0;
        int subTreeValue = solve(root->left) + solve(root->right) + root->val;
        if (abs(subTreeValue*2 - sum) < abs(best*2 - sum)) {
            best = subTreeValue;    // 求一个更加逼近于sum/2的值，这样乘积也更大一点
        }   // 不这样的话全局存一个long long也可以，每次比较最小的值就可以了
        return subTreeValue;
    }
public:
    int maxProduct(TreeNode* root) {
        sum = 0;
        best = 0;
        dfs(root);  // 求书上所有节点的总值
        solve(root);
        return (static_cast<long long>(best) * static_cast<long long>(sum - best)) % 1000000007;
    }
};