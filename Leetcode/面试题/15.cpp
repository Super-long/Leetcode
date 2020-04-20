// 三数之和
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int j = 1; j < nums.size(); ++j){
            int item = nums[j];
            //cout << item << endl;
            int lhs = 0, rhs = nums.size() - 1;
            for(int i = 0; i < nums.size(); ++i){
                //cout << nums[lhs] << " " << nums[rhs] << endl;
                if(lhs == rhs) break;
                if(lhs == i || rhs == i || lhs == j || rhs == j) continue;
                if(nums[lhs] + nums[rhs] + item > 0){
                    --rhs;
                } else if (-item == nums[lhs] + nums[rhs]){
                    vector<int> vec = {item, nums[lhs], nums[rhs]};
                    sort(vec.begin(), vec.end());
                    res.emplace_back(vec);
                    --rhs;
                } else {
                    ++lhs;
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    auto res = sol.threeSum(vec);
    for(auto item : res){
        for(size_t i = 0; i < item.size(); i++){
            cout << item[i] << " ";
        }
        putchar('\n');
    } 
    return 0;
}