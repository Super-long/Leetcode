#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, tuple<int, int, int>> mp;
        for (size_t i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                get<0>(mp[nums[i]])++;
                get<2>(mp[nums[i]]) = i;
            } else {
                mp[nums[i]] = make_tuple(1, i, i);  // 插入两个i还是挺巧妙的
            }
        }
        
        int target = 0;
        int res = 0;
        for(auto& [_, item] : mp){
            if(get<0>(item) >= target){
                target = item.get(0);
                res = max<int>(res, get<2>(item) - get<1>(item) + 1);
            }
        }
        return res;
    }
};