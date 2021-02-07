#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 当然把栈改成双端队列，插入的时候更具层数选择前插还是后插也可以
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        bool odd = true;
        stack<TreeNode*> stk;
        stk.push(root);
        vector<vector<int>> res;
        while(stk.size()){
            vector<int> path;
            stack<TreeNode*> temp;
            int len = stk.size();
            while(len--){
                auto item = stk.top();
                path.push_back(item->val);
                stk.pop();
                if(odd){
                    if(item->left) temp.push(item->left);
                    if(item->right) temp.push(item->right);
                    odd = false;
                } else {
                    if(item->right) temp.push(item->right);
                    if(item->left) temp.push(item->left);
                    odd = true;
                }
            }
            stk = temp;
            res.push_back(std::move(path));
        }
        return res;
    }
};