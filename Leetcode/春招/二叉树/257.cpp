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
    vector<string> vecRoutine;
    deque<int> que;
public:
    void GetResult() noexcept { 
        string str;
        for(size_t i = 0; i < que.size(); ++i) {
            if(i == que.size() - 1){
                str += to_string(que[i]);
                continue;
            }
            str += to_string(que[i]) + "->";
        }
        vecRoutine.emplace_back(std::move(str));
        return;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        que.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            GetResult();
            return;
        }
        
        dfs(root->left);
        dfs(root->right);
        que.pop_back();

        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return std::move(vecRoutine);
    }
};