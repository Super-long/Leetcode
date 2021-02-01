#include <bits/stdc++.h>
using namespace std;

// 需要去重的全排列
/* class Solution { // 这样写swap时会破坏有序条件
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            if(i != start && nums[i] == nums[i-1]) continue;
            swap(nums[i], nums[start]);

            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};  */

class Solution{
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1] && used[i - 1] == false) continue;
            if(used[i] == false){   // 不能开始时直接指定的起始值，因为可能后面为true，前面均为false
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> flags(nums.size());
        dfs(nums, flags);
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {0,1,0,0,9};
    auto res = sol.permuteUnique(vec);
    for (size_t i = 0; i < res.size(); i++){
        for(auto x : res[i]){
            cout << x << " ";
        }
        putchar('\n');
    }
    return 0;
    
}