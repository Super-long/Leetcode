#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if(!tree) return {};
        queue<TreeNode*> que;
        ListNode* head;
        ListNode now(0);
        head = &now;
        que.push(tree);
        vector<ListNode*> result;

        while (!que.empty()) {
            auto len = que.size();
            while(len--){
                auto item = que.front();
                que.pop();
                head->next = new ListNode(item->val);
                head = head->next;
                if(item->left) que.push(item->left);
                if(item->right) que.push(item->right);
            }
            result.push_back(now.next);
            now.next = nullptr;
            head = &now;
        }
        return result;
    }
};