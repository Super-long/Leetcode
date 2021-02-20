#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if(row*col < r*c) return nums;
        vector<vector<int>> res;
        for (size_t i = 0; i < r; i++){
            vector<int> item;
            for (size_t j = 0; j < c; j++){
                int temp = c*i+j;
                item.push_back(nums[temp/col][temp%col]);
            }
            res.emplace_back(std::move(item));
        }
        return res;        
    }
};