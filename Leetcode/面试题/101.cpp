// 对称二叉树
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

    bool check(TreeNode* lhs, TreeNode* rhs){
        if(lhs && !rhs) return false;
        if(!lhs && rhs) return false;
        if(!lhs && !rhs) return true;
        bool flag = rhs->val == lhs->val;
        return flag && check(rhs->left, lhs->right) && check(rhs->right, lhs->left);
    }
};

// 迭代也很简单，就是层序遍历，检查每一层是否为回文，指针为空就插入一个一定不存在的值，检查的时候每层乘个2，