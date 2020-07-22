// 在每个树行中找最大值
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution {    // bfs
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> que;
        vector<int> res;
        int pre = 1;
        que.push(root);
        int cur = 0;    //记录此层中节点数
        while(que.size()){
            int Max = INT_MIN;
            while(pre--){
                auto Top = que.front();
                que.pop();
                Max = max(Max, Top->val);
                if(Top->left){
                    que.push(Top->left);
                    cur++;
                }
                if(Top->right){
                    que.push(Top->right);
                    cur++;
                }
            }
            pre = cur;
            cur = 0;
            res.push_back(Max);
        }
        return res;
    }
}; */

class Solution {    // dfs 快于bfs
private:
    vector<int> res;
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        res.clear();
        
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(level >= res.size()) res.push_back(INT_MIN); // 一定是一个一个上涨的
        res[level] = max(res[level], root->val);
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
        return;
    }
};