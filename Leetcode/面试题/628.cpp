#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool flag = false;
    void changeNegative(int target, int& lhs, int& rhs){
        flag = true;
        if(target < lhs){
            rhs = lhs;
            lhs = target;
        } else if(target < rhs){
            lhs = target;
        }
        return;
    }

    void changePositive(int target, int& lhs, int& bhs, int& rhs){
        if(target > lhs){
            rhs = bhs;
            bhs = lhs;
            lhs = target;
        } else if(target > bhs){
            rhs = bhs;
            bhs = target;
        } else if(target > rhs){
            rhs = target;
        }
        return;
    }

public:
    int maximumProduct(vector<int>& nums) {
        int negative1 = INT_MAX;
        int negative2 = INT_MAX;
        int positive1 = INT_MIN;
        int positive2 = INT_MIN;
        int positive3 = INT_MIN;
        
        for (size_t i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                changePositive(nums[i], positive1, positive2, positive3);
            } else {
                changeNegative(nums[i], negative1, negative2);
            }
        }

        int temp = positive1 * positive2 * positive3;

        if(flag){
            return max(temp, negative1*negative2*positive1);
        }
        return temp;
    }
};
/*
确实巧妙，用一个式子统一了所有的情况：
1. 全负数
2. 全正数
3. 两负三正
4. 一负一正/全正
*/
/* 
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // 最小的和第二小的
        int min1 = INT_MAX, min2 = INT_MAX;
        // 最大的、第二大的和第三大的
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int x: nums) {
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }

            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }
        }

        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
 */
int main(){
    Solution sol;
    vector<int> nums = {-3,1,2,3,4};
    cout << sol.maximumProduct(nums) << endl;
    return 0;
}