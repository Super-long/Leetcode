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

class Solution {    // 把我的思路写出来了，不过貌似思路是错的
private:
    TreeNode* node = nullptr;
    int Value;
    bool flag;  // false left; true right;
    int dfs(TreeNode* root){
        if(!root || node != nullptr) return 0;
        int lhs = dfs(root->left);
        int rhs = dfs(root->right);
        if(lhs < Value && Value < root->val){
            node = root;
            flag = false;
        }  else if (rhs < Value && Value < root->val){
            node = root;
            flag = true;
        }
        return max(lhs, rhs);
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        Value = val;
        dfs(root);
        TreeNode* tree = new TreeNode(val);
        if(!node){
            tree->left = root;
            return tree;
        }
        if(flag){
            auto rhs = root->right;
            root->right = tree;
            tree->right = rhs;
        } else {
            auto lhs = root->left;
            root->left = tree;
            tree->left = lhs;
        }
        return root;
    }
};

class Solution {    // 这个可以过
private:
    TreeNode* node = nullptr;
    int Value;
    bool flag;  // false left; true right;
    int dfs(TreeNode* root){
        if(!root || node != nullptr) return 0;
        cout << root->val << endl;
        int rhs = dfs(root->right);
        if (rhs < Value && Value < root->val){
            node = root;
            flag = true;
        }
        return max(rhs, root->val);
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        Value = val;
        dfs(root);
        TreeNode* tree = new TreeNode(val);
        if(!node){
            tree->left = root;
            return tree;
        }
        if(flag){
            auto rhs = node->right;
            node->right = tree;
            tree->left = rhs;
        }
        return root;
    }
};

class Solution {    // 确实巧妙
    public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == nullptr || root->val < val) {
            TreeNode* tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        }
        TreeNode* right = insertIntoMaxTree(root->right,val);
        root->right = right;
        return root;
    }
};
