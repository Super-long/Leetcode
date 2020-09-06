#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution { // 思路错了 [1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
private:
    set<int> vec;
    bool dfs(TreeNode* root, int depth){
        if(!root){
            return false;
        }
        bool lhs = dfs(root->left, depth + 1);
        bool rhs = dfs(root->right, depth + 1);
        if(lhs == false || rhs == false){
            vec.insert(depth);
            cout << depth << endl;
        }
        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root, 0);
        if(vec.size() > 2) return false;
        return true;
    }
}; */

/*
height(p)={ 
0           p 是空节点
max(height(p.left),height(p.right))+1   p 是非空节点
​	
​也就是叶子节点的深度之差是可以超过2的
*/
class Solution {    // 以前对平衡这个概念不对
public:
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};