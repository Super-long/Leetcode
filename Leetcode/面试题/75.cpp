#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    void sortColors(vector<int>& nums) {    // 一次遍历 常数空间
        int index = 0;
        int zero  = 0;
        int one   = 0;
        int two   = 0;
        for (int i = 0; i < nums.size(); i++){
            if(!nums[i]){
                ++zero;
            } else if(nums[i] == 1){
                ++one;
            } else {
                ++two;
            }
            if(zero){
                nums[index++] = zero--;
            }
        }
        while(one--){
            nums[index++] = 1; 
        }
        while(two--){
            nums[index++] = 2;
        }
        return;
    }
};
 */
class Solution {
public:
    void sortColors(vector<int>& nums) {    // 一种比我想的更优的算法
        int lhs = 0, rhs = nums.size() - 1;
        for (int i = 0; i <= rhs; i++){
            if(nums[i] == 0){
                swap(nums[i], nums[lhs]);
                ++lhs;
            } else if(nums[i] == 2){
                swap(nums[i], nums[rhs]);
                --rhs;
                --i;
            }
        }
        return;
    }
};