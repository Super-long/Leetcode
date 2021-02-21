#include <bits/stdc++.h>
using namespace std;

/* class Solution {    // 用平衡树可以解；单调队列也可以解
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int lhs = 0;
        int res = 0;
        map<int, int> vis;
        for (size_t i = 0; i < nums.size(); i++){
            vis[nums[i]]++;
            cout << vis.begin()->first << " " << vis.rbegin()->first << endl;
            while(lhs < i && vis.rbegin()->first - vis.begin()->first > limit){
                vis[nums[lhs]]--;
                cout << nums[lhs] << " - " <<vis[nums[lhs]] << endl;
                if(vis[nums[lhs]] == 0){
                    vis.erase(nums[lhs]);
                }
                lhs++;
            }
            res = max<int>(res, i - lhs + 1);
        }
        return res;
    }
}; */

class Solution {    // 单调队列O(N)可以维护区间最大值
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> queMin, queMax;
        int lhs = 0;
        int res = 0;
        for (size_t i = 0; i < nums.size(); i++){
            while(!queMin.empty() && queMin.back() > nums[i]){
                queMin.pop_back();
            }
            while(!queMax.empty() && queMax.back() < nums[i]){
                queMax.pop_back();
            }
            queMax.push_back(nums[i]);  // 单调队列中应该有重复值
            queMin.push_back(nums[i]);

            while(!queMax.empty() && !queMin.empty() && queMax.front() - queMin.front() > limit){
                if(nums[lhs] == queMin.front()){
                    queMin.pop_front();
                }

                if(nums[lhs] == queMax.front()){
                    queMax.pop_front();
                }
                lhs++;
            }
            res = max<int>(res, i - lhs + 1);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {8,2,4,7};
    cout << sol.longestSubarray(vec, 4) << endl;
    return 0;
}