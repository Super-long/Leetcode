// 二叉树视图
#include <bits/stdc++.h>
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> que;
        queue<int> depthque;
        que.push(root);
        depthque.push(0);
        int max_depth = -1;
        unordered_map<int, int> mp;
        while(que.size()){
            TreeNode* item = que.front(); que.pop();
            int depth = depthque.front(); depthque.pop();
            if(!item) continue;
            max_depth = max(depth, max_depth);
            mp[max_depth] = item->val;
            que.push(item->left);
            depthque(depth+1);
            que.push(item->right);
            depthque(depth+1);
        }
        vector<int> rightView;
        for (int depth = 0; depth <= max_depth; ++depth) {
            rightView.push_back(mp[depth]);
        }
        return rightView;
    }
}; */

class Solution{
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;        
    }
    void helper(TreeNode* root,int level,vector<int>& res){
        if(!root) return;
        if(res.size()==level) res.push_back(root->val);
        helper(root->right,level+1,res);
        helper(root->left,level+1,res);
    }  
};