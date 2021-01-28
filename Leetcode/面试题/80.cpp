#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lhs = 0;
        int flag = 1;
        for (size_t i = 1; i < nums.size(); i++){
            if(flag < 2 && nums[i] == nums[lhs]){
                lhs++;
                flag++;
            } else if(flag <= 2 && nums[i] != nums[lhs]){
                flag = 1;
                lhs++;
            }
            nums[lhs] = nums[i];
        }
        return lhs + 1;
    }
};