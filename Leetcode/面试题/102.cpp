// 二叉树的层次遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<std::pair<TreeNode*, int>> que;
        que.push(make_pair(root,0));
        vector<vector<int>> res;
        if(root != nullptr) res.push_back(vector<int>());
        int deepth = 0;
        while(que.size()){
            auto Top = que.front();
            que.pop();
            if(Top.first != nullptr){
                if(Top.second != deepth){
                    ++deepth;
                    res.push_back(vector<int>());
                }
                res[deepth].push_back(Top.first->val);
                que.push(make_pair(Top.first->left,Top.second+1));
                que.push(make_pair(Top.first->right,Top.second+1));
            }
        }
        return std::move(res);
    }
};