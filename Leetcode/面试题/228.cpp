// 汇总区间
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    string Convert(int lhs, int rhs, const vector<int>& nums){
        string temp;
        if(rhs != lhs)
            temp = to_string(nums[lhs]) + "->" + to_string(nums[rhs]);
        else 
            temp = to_string(nums[lhs]);
        return temp;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(!nums.size()) return vector<string>();
        int lhs = 0; 
        for(size_t i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i-1]+1){
                res.push_back(std::move(Convert(lhs, i-1, nums)));
                lhs = i;
            }
        }
        res.push_back(std::move(Convert(lhs, nums.size()-1, nums)));
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {};
    auto res = sol.summaryRanges(vec);
    for(auto x : res){
        cout << x << endl;
    }
    return 0;
}