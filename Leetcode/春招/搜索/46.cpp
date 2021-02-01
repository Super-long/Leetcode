#include <bits/stdc++.h>
using namespace std;

// 不用去重的全排列
class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start){
        if(start == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); ++i){
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,3,4};
    auto res = sol.permute(vec);
    for (size_t i = 0; i < res.size(); i++){
        for(auto x : res[i]){
            cout << x << " ";
        }
        putchar('\n');
    }
    return 0;
    
}