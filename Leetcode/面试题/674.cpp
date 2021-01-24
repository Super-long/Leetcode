#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(!nums.size()) return 0;
        int index = 0;
        int res = 1;
        for (size_t i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                res = max<int>(res, i - index + 1);
            } else {
                index = i;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,3,5,4,7};
    cout << sol.findLengthOfLCIS(vec) << endl;
    return 0;
}