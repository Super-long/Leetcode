#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:    // 中序的N-K，也就是倒着中序遍历的第K个值
    int ans = -1;   // 假设没有负数
    int itear = 0;
    void dfs(TreeNode* root){
        if(!root || ans != -1) return;
        dfs(root->right);
        if(!--itear) ans = root->val;
        dfs(root->left);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        itear = k;
        dfs(root);
        return ans;
    }
};

class Solution {    // 模板级的中序遍历代码
public:
    int kthLargest(TreeNode* root, int k) {
        vector<TreeNode*> worker;
        while (root || worker.size()) {
            while (root) {
                worker.push_back(root); // 根入栈
                root = root->right;     // 访问右子树，向下探
            }
            root = worker.back(), worker.pop_back(); // 出栈
            if (!--k) return root->val;
            root = root->left;          // 访问左子树
        }
        return 0;
    }
};
