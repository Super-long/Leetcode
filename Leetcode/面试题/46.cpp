// 全排列
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int index){
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }
        for(size_t i = index; i < nums.size(); i++){
            swap(nums[i], nums[index]);
            dfs(nums, index+1);
            swap(nums[i], nums[index]);
        }
        return;
    }
};

/* class Solution { // 两种是有区别的 函数的方法是去重的 比如样例中的{1,1,1}
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        sort(nums.begin(), nums.end());
        do
        {
            vector<int> vec(nums.size());
            for(int i=0;i<nums.size();i++){
                vec = nums;
            }
            res.emplace_back(std::move(vec));
        }while(next_permutation(nums.begin(),nums.begin()+nums.size()));
        return res;
    }
}; */

int main(){
    Solution sol;
    vector<int> vec = {1,1,1};
    auto x = sol.permute(vec);
    cout << "size : " << x.size() << endl;
    for(auto item : x){
        for(auto i : item){
            cout << i << " ";
        }
        putchar('\n');
    }
    return 0;
}