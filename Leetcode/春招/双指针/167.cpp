#include <bits/stdc++.h>
using namespace std; 

class Solution {    // 这个题也可以二分，哈希表，不过那样有点蠢，前者时间复杂度nlogn，后者空间复杂度为n
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lhs = 0;
        int rhs = numbers.size() - 1;
        while(lhs < rhs){
            cout << numbers[lhs] << " " <<  numbers[rhs] << endl;
            if(numbers[lhs] + numbers[rhs] < target){
                lhs++;
            } else if(numbers[lhs] + numbers[rhs] > target){
                rhs--;
            } else {
                return {lhs + 1, rhs + 1};
            }
        }
        return {-1,-1};
    }
};

int main(){
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10};
    auto temp = sol.twoSum(nums, 15);
    for(auto x : temp){
        cout << x << " ";
    } 
    return 0;
}