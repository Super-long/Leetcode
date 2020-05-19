//二叉树中的列表
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    ListNode* List;
    bool result;
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        List = head;
        result = false;
        dfs(root);
        return result;
    }

    void dfs(TreeNode* root){
        if(root == nullptr) return;
        if(result) return; //已经找到答案
        result = check(root, List);
        dfs(root->left);
        dfs(root->right);
    }

    bool check(TreeNode* root, ListNode* head){
        if(head == nullptr) return true; //链表搜完了 证明全部匹配
        if(root==nullptr && head != nullptr) return false;// 树完了 链表没完 不全部匹配

        bool flag = (root->val == head->val);
        if(!flag) return false;

        flag = check(root->left, head->next) || check(root->right, head->next);
        return flag;
    }
};