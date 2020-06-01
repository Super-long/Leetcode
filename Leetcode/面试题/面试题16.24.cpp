// 数对和
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 写的太丑陋
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(auto x : nums){
            mp[x]++;
        }
        vector<vector<int>> res;
        for(auto item : mp){
            if(mp.find(target - item.first) != mp.end()){
                if(item.first == target -item.first && mp[item.first]>=2){
                    for(size_t i = 0; i < mp[item.first]/2; i++){
                        res.push_back({item.first, target - item.first});
                    }// mp也不用减, 因为永远不会跑到了
                    continue;
                }else if(item.first == target -item.first && mp[item.first]<2){
                    continue;
                }
                int loop = min(mp[item.first], mp[target - item.first]);
                mp[item.first]-=loop;
                mp[target - item.first]-=loop;
                for(size_t i = 0; i < loop; i++){
                    res.push_back({item.first, target - item.first});
                }
            }
        }
        return res;
    }
}; */

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        static auto speedup = [](){ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();
        vector<vector<int>> res;
        if (nums.empty()) return res;
        sort(nums.begin(), nums.end());
        auto left = nums.begin(), right = nums.end() - 1;
        while (left < right) {
            if (*left + *right == target) res.push_back({*left++, *right--});
            else if (*left + *right < target) ++left;
            else --right;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1, 2, 0, 0, 2, 1, 0, 2, 2, 3};
    auto item = sol.pairSums(vec, 2);
    for(auto x : item){
        for(auto y : x){
            cout << y << " ";
        }
        putchar('\n');
    }
    return 0;
}