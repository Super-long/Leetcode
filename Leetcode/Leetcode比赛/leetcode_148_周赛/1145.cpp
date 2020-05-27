// 二叉树着色游戏
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution { // 垃圾代码
private:
int n;
int x;
int res;
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->n = n;
        this->x = x;
        res = 0;
        dfs(root);

        int sum = 1;
        check(root->left, sum);
        if(sum == n/2){
            res = root->val;
            return;
        }
        sum = 1;
        check(root->right, sum);
        if(sum == n/2){
            res = root->val;
            return;
        } 
        return res == x ? false : true;
    }

    void dfs(TreeNode* root){
        if(root == nullptr) return;
        int sum = 0;
        check(root->left, sum);
        if(sum == n/2){
            res = root->val;
            return;
        }
        sum = 0;
        check(root->right, sum);
        if(sum == n/2){
            res = root->val;
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }

    void check(TreeNode* root, int& sum){
        if(!root) return;
        if(root->left){
            sum++;
            check(root->left, sum);
        }
        if(root->right){
            sum++;
            check(root->right, sum);
        }
    }
}; */

class Solution { // 巧妙的解法
public:
    TreeNode* find_x_node(TreeNode* start, int x){
        TreeNode* res;
        if(start->val == x)return start;
        if(start->left){
            res = find_x_node(start->left,x);
            if(res)return res;
        }
        if(start->right){
            res = find_x_node(start->right,x);
            if(res)return res;
        }
        return res;
    }

    int NodeCnt(TreeNode* node){
        if(node==NULL)return 0;
        return 1+NodeCnt(node->left)+NodeCnt(node->right);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        //  find x's node
        TreeNode* nodex = find_x_node(root, x);

        int left_cnt = NodeCnt(nodex->left);
        int right_cnt = NodeCnt(nodex->right);
        int up_cnt = n - left_cnt - right_cnt - 1;
        
        int MAX = max(max(left_cnt, right_cnt), up_cnt);
        return MAX > n/2 ? true : false;
/*         if(left_cnt > right_cnt+up_cnt+1 || right_cnt > left_cnt+up_cnt+1 || up_cnt > left_cnt+right_cnt+1){
            return true;
        }

        return false; */
    }
};