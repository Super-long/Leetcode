#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(int index, const vector<int>& nums){
        if(index == nums.size()){
            return;
        }
        for (size_t i = index; i < nums.size(); i++){
            path.push_back(nums[i]);
            res.push_back(path);
            dfs(i + 1, nums);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        res.push_back({});
        return res;
    }
};