#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> vis(nums.size(), false);
        vector<int> item;
        dfs(nums, item, vis);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& item, vector<bool>& vis){
        if(item.size() == nums.size()){
            res.push_back(item);
            return;
        }
        for (int i = 0; i < nums.size(); i++){
            // nums[i] == nums[i - 1] 同一层是重复的
            if(i > 0 && nums[i] == nums[i - 1] && vis[i - 1] == false) { 
                continue;
            }
            if(vis[i] == false){
                vis[i] = true;
                item.push_back(nums[i]);
                dfs(nums, item, vis);
                item.pop_back();
                vis[i] = false;
            }
        }
    }
};