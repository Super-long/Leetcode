// 有多少小于当前数字的数字
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec;
        for(size_t i = 0; i < nums.size(); i++){
            int sum = 0;
            for(size_t j = 0; j < nums.size(); j++){
                if(nums[j] < nums[i]){
                    sum++;
                }
            }
            vec.push_back(sum);
        }
        return vec;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {7,7,7,7};
    auto x = sol.smallerNumbersThanCurrent(vec);
    for(auto i : x){
        cout << i << endl;
    }
    return 0;
}