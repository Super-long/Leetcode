#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 这题是层序变量；103是锯齿状遍历，比这个稍微难一点
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {}; 
        queue<TreeNode*> que;
        int num = 0;
        vector<vector<int>> result;
        que.push(root);
        while(que.size()){
            size_t len = que.size();
            vector<int> item;
            for (size_t i = 0; i < len; i++){
                auto temp = que.front();
                item.push_back(temp->val);
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            result.emplace_back(std::move(item));
        }
        return result;
    }
};