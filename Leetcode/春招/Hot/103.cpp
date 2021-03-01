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

// 偶 左取 尾从左到右插
// 奇 右取 首从右往左插

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        deque<TreeNode*> que;
        que.push_back(root);
        bool isLeft = true;
        vector<vector<int>> res;
        while(que.size()){
            vector<int> item;
            int len = que.size();
            while(len--){
                if(isLeft){
                    auto node = que.front();
                    item.push_back(node->val);
                    que.pop_front();
                    if(node->left) que.push_back(node->left);
                    if(node->right) que.push_back(node->right);
                } else {
                    auto node = que.back();
                    item.push_back(node->val);
                    que.pop_back();
                    if(node->right) que.push_front(node->right);
                    if(node->left) que.push_front(node->left);
                }
            }
            res.push_back(std::move(item));
            isLeft = isLeft ? false : true;
        }
        return res;
    }
};