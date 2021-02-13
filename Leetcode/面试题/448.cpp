#include <bits/stdc++.h>
using namespace std;

class Solution {    // 比较像脑筋急转弯
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            nums[(nums[i] - 1)%len] += len; // 这里的取余很关键
        }
        vector<int> res;
        for (size_t i = 0; i < nums.size(); i++){
            if(nums[i] <= len){
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {4,3,2,7,8,2,3,1};
    auto res = sol.findDisappearedNumbers(vec);
    for(auto x : res)
    std::cout << x << endl;
    return 0;
}