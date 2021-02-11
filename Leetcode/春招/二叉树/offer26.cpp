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
    bool isSub(TreeNode *left, TreeNode *right) {
        if(right == nullptr) return true;
        if(left == nullptr) return false;
        if(left->val != right->val) return false;
        return isSub(left->left, right->left) && isSub(left->right, right->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr) return false;
        bool flag = isSub(A, B);
        bool lhs = isSubStructure(A->left, B);
        bool rhs = isSubStructure(A->right, B);
        return flag || lhs || rhs;
    }
};