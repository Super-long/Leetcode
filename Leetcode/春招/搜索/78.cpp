#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(const vector<int>& nums, size_t start){
        size_t len = nums.size();
        if(len <= start){
            return;
        }
        for (size_t i = start; i < len; i++){
            path.push_back(nums[i]);
            res.push_back(path);
            dfs(nums, i + 1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        res.push_back({});
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,3};
    auto res = sol.subsets(vec);
    cout << "result : \n";
    for(auto item : res){
        for(auto x : item){
            cout << x << " ";
        }
        putchar('\n');
    }
    return 0;
}