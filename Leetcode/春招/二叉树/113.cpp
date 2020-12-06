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
    vector<vector<int>> res;
    vector<int> item;
public:
    void dfs(TreeNode* root, int value){
        if(root == nullptr) return;
        item.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr && value == root->val){
            res.push_back(item);
            item.erase(item.end() - 1); // 当然这里可以不return和erase，直接退出，后面两次函数调用以后也是会erase的；
            return;
        }

        dfs(root->left, value - root->val);
        dfs(root->right, value - root->val);
        item.erase(item.end() - 1);

        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return std::move(res);
    }
};