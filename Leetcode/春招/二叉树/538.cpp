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

class Solution {
private:
/*     int dfs(TreeNode* root, int base){   // 写的是个锤子，答案就是反向中序遍历
        if(root == nullptr) return 0;
        int rhs = dfs(root->right, base);
        auto temp = root->val;
        root->val += rhs + base ; 
        int lhs = dfs(root->left, root->val);
        return lhs + temp;
    } */
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {  // 累加树其实就是中序遍历，没看懂这题做不了
        if(root){
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};