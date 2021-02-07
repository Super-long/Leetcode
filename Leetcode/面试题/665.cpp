#include <bits/stdc++.h>
using namespace std;

class Solution {    // 这个简单题不太简单;第一遍写的是个锤子
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = true;
        if(nums.size() == 1) return true;
        for (size_t i = 0; i < nums.size() - 1; i++){
            int temp = 0;
            if(i == 0){
                temp = nums[1];
            } else {
                temp = nums[i-1];
            }

            if(nums[i] < temp && flag){
                nums[i] = temp;
                flag = false;
            } else {
                return false;
            }
        }
        return true;
    }
};

class Solution {    // 查找有几个num[i] > num[i+1]，显然要返回true，这个值最多一个，当然就算只有一个也不一定是答案，还需要检测
public:
    bool checkPossibility(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int x = nums[i], y = nums[i + 1];
            if (x > y) {
                nums[i] = y;
                if (is_sorted(nums.begin(), nums.end())) {
                    return true;
                }
                nums[i] = x; // 复原
                nums[i + 1] = x;
                return is_sorted(nums.begin(), nums.end());
            }
        }
        return true;
    }
};