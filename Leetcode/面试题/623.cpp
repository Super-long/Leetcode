// 在二叉树中增加一行
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
    int v; // 值为v
    int d; // d层
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        this->v = v;
        this->d = d-1;
        if(d == 1){
            TreeNode* Temp = new TreeNode(v);
            Temp->left = root;
            return Temp;
        }
        dfs(1, root);
        return root;
    }

    void dfs(int deepth, TreeNode* root){
        if(!root) return;
        if(deepth == d){
            TreeNode* lhs = new TreeNode(v);
            if(root->left){
                TreeNode* Temp = root->left;
                root->left = lhs;
                lhs->left = Temp;
            }else {
                root->left = lhs;
            }

            TreeNode* rhs = new TreeNode(v);
            if(root->right){
                TreeNode* Temp = root->right;
                root->right = rhs;
                rhs->right = Temp;
            }else {
                root->right = rhs;   
            }
            return;
        }
        dfs(deepth+1, root->left);
        dfs(deepth+1, root->right);
    }
};