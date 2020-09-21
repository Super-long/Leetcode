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
vector<int> pre;
vector<int> items;
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        pre.resize(items.size());
        for(int i = 0; i < items.size(); ++i){
            if(!i){
                pre[i] = pre[i-1] + items[i];
            }else {
                pre[i] = items[i];
            }
        }
        conversion(root);
        return root;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        items.push_back(root->val);
        dfs(root->right);
        return; 
    }

    void conversion(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        int index = upper_bound(items.begin(), items.end(), root->val) - items.begin();
        if(index < items.size()){ // 仅仅一个节点的时候
            root->val += pre.back() - pre[index-1];
        }
        dfs(root->right);
        return; 
    }
};