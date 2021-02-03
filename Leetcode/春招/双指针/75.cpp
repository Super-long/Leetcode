#include <bits/stdc++.h>
using namespace std;

// 不原地的话其实计数排序也可以

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index = 0;
        for (size_t i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                swap(nums[index], nums[i]);
                index++;
            }
        }
        for (size_t i = index; i < nums.size(); i++){
            if(nums[i] == 1){
                swap(nums[index], nums[i]);
                index++;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index1 = 0;
        int index2 = 0;
        for (size_t i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                swap(nums[index2++], nums[i]);
            } else if(nums[i] == 0){
                swap(nums[index2], nums[i]);
                swap(nums[index2++], nums[index1++]);
            }
        }        
    }
};