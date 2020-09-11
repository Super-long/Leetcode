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
    vector<string> res;
    void dfs(TreeNode* root, string str){
        string number = to_string(root->val);
        bool lhs = root->left; 
        bool rhs = root->right;
        if(lhs) dfs(root->left, str + number + "->");
        if(rhs) dfs(root->right, str + number + "->");
        if(!lhs && !rhs){
            str += number;
            res.push_back(std::move(str));
        }
        return;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        dfs(root, "");
        return res;
    }
};