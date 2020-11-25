#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {    // 这题用二分棒呆了，但是我没用
private:
    int len = 0;
    int number = 0;
public:
    int countNodes(TreeNode* root) {    
        if(!root) return 0;
        bool flag = false;
        count(root);
        dfs(root, flag, 1);
        return (1<<len-1) - 1 + number;
    }

    void count(TreeNode* root) {
        if(!root){
            return;
        } 
        ++len;
        count(root->left);
    }

    void dfs(TreeNode* root, bool& flag, int depth){
        if(!root || flag){
            return;
        }

        if(root->left == nullptr && root->right == nullptr){
            if(depth < len){
                flag = true;
                return;
            }
            ++number;
            return;
        }

        dfs(root->left, flag, depth + 1);
        dfs(root->right, flag, depth + 1);
    }
};

