// 出现次数最多的子树元素和
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
    vector<int> res;
    unordered_map<int, int> mp;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        res.clear();
        dfs(root);
        int Max = INT_MIN;
        for(auto x : mp){
            Max = max(Max, x.second);
        }
        for(auto x : mp){
            if(x.second == Max)
                res.push_back(x.first);
        }
        return res;
    }

    int dfs(TreeNode* root){
        if(!root) return 0;
        int Temp = root->val + dfs(root->left) + dfs(root->right);
        mp[Temp]++;
        return Temp;
    }
};