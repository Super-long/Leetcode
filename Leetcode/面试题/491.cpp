#include <bits/stdc++.h>
using namespace std;

class Solution {
private:    // [1,2,3,4,5,6,7,8,9,10,1,1,1,1,1] 答案错误
    vector<vector<int>> res;
    void dfs(vector<int>& item, vector<int>& nums, int startID){
        if(startID >= nums.size()) return;
        int pre = 0;
        if(item.empty()){
            pre = nums[startID];
        } else {
            pre = item.back();
        }
        unordered_map<int, bool> mp;
        for (int i = startID; i < nums.size(); i++){
            if(nums[i] >= pre){
                pre = nums[i];
            }else {
                continue;
            }
            if(mp.find(nums[i]) != mp.end()){
                continue; // 不需要再跑底下的dfs 因为发现了相同的数，其后较大的值前面的那个数已经遍历过了
            }else {
                item.push_back(nums[i]);
                if(item.size() >= 2){
                    vector<int> temp = item;
                    res.push_back(std::move(temp));
                }
            }
            dfs(item, nums, i + 1);
            mp[pre] = true;
            item.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> item;
        dfs(item, nums, 0);
        return res;
    }
};

class Solution {    // 官方的题解比我简洁许多 这告诉我回溯类题目先想解答树
public:
    vector<int> temp; 
    vector<vector<int>> ans;

    void dfs(int cur, int last, vector<int>& nums) {
        if (cur == nums.size()) {
            if (temp.size() >= 2) {
                ans.push_back(temp);
            }
            return;
        }
        if (nums[cur] >= last) {
            temp.push_back(nums[cur]);
            dfs(cur + 1, nums[cur], nums);
            temp.pop_back();
        }
        if (nums[cur] != last) {
            dfs(cur + 1, last, nums);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, INT_MIN, nums);
        return ans;
    }
};
