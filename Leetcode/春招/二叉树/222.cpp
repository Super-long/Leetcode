#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

                    // 判断完全二叉树的结点
class Solution {    // 这个题用二分最好;  当然这种做法是错误的，因为题目没有限定结点内的值是顺序的，只能用位运算
int length(TreeNode *root) {
    if(root == NULL) return 0;
    return length(root->left) + 1;
}

// 根据传入的值求深度
int dfs(TreeNode *root, int value){
    stack<int> stk;
    while(value!=0){
        //cout << value << endl;
        stk.push(value);
        value /= 2;
    }
    if(stk.size() == 0) return 0;
    stk.pop();

    int depth = 1;
    //cout << stk.size() << endl;
    while(stk.size() > 0){
        auto temp = stk.top();
        stk.pop();
        if(root->left != NULL && root->left->val == temp){
            root = root->left;
        } else if(root->right != NULL && root->right->val == temp){
            root = root->right;
        } else {
            break;
        }
        depth++;
    }
    return depth;
}

public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int len = length(root);
        int lhs = 1 << (len - 1);
        int rhs = (1 << len) - 1;  // 第len层可能的值的范围
        int res = 0;
        while(lhs < rhs){
            int mid = lhs + (rhs - lhs) / 2;
            int temp = dfs(root, mid);
            //cout << mid << " " <<temp << " " << lhs << " " << rhs << endl;
            if(temp < len){
                rhs = mid - 1;
            } else {
                lhs = mid + 1;
                res = mid;
            }
        }
        cout << res << " " << lhs << endl;
        auto x = dfs(root, lhs);
        cout << x << endl;
        if(len == x) return lhs;
        return res;
    }
};
class Solution {  
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int level = 0;
        TreeNode* node = root;
        while (node->left != nullptr) {
            level++;
            node = node->left;
        }
        
        int low = 1 << level, high = (1 << (level + 1)) - 1;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (exists(root, level, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    bool exists(TreeNode* root, int level, int k) {
        int bits = 1 << (level - 1);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if (!(bits & k)) {
                node = node->left;
            } else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
};