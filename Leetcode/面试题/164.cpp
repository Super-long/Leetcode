#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        long MIN = INT_MAX+1;
        long MAX = -1;
        for (size_t i = 0; i < nums.size(); ++i){
            if(nums[i] > MAX) MAX = nums[i];
            if(nums[i] < MIN) MIN = nums[i];
        }
        
        int d = max<int>(1, (MAX - MIN) / (nums.size() - 1));
        int bucketSize = (MAX - MIN) / d + 1;

        vector<pair<int,int>> buket(bucketSize, {-1,-1});

        for (size_t i = 0; i < nums.size(); i++){
            int idx = (nums[i] - MIN) / d;
            if(buket[idx].second == -1){
                buket[idx].second = buket[idx].first = nums[i];
            } else {
                if(buket[idx].second < nums[i]){
                    buket[idx].second = nums[i];
                } else if(buket[idx].first > nums[i]) {
                    buket[idx].first = nums[i];
                }
            }
        }
        int ret = 0;
        int prev = -1;
        for (size_t i = 0; i < bucketSize; i++){
            if(buket[i].first == -1) continue;
            if(prev != -1){
                ret = max(ret, buket[i].first - prev);
            }
            prev = buket[i].second;
        }
        
        return ret;
    }
};