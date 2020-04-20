#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // 显然去重是难点
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int > vtemp;
        int len = nums.size();
        sort(nums.begin(),nums.end());//sort the input
        for(int i=0;i<len-2;i++){
            if(i ==0 ||(i>0 && nums[i] != nums[i-1])){ // 去掉重复的值
                int p1 = i+1, p2 = len-1; // set two pointers
                while(p1 < p2){
                    if(nums[p1] + nums[p2] < -nums[i]){
                        p1++;
                    }else if(nums[p1] + nums[p2] == -nums[i]){
                        if(p1 == i+1){ // 特判第一个值
                            ret.push_back({nums[i], nums[p1], nums[p2]});
                        }else if(nums[p1] != nums[p1-1]){ // 因为上一个值已经包含这个解了
                            ret.push_back({nums[i], nums[p1], nums[p2]});
                        }
                        p1++,p2--; // 一个值已经算过的话 另一个可能也要更新 不然又是只有一个值
                    }else{
                         p2--;
                    }
                }
            }
        }
        return ret;
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