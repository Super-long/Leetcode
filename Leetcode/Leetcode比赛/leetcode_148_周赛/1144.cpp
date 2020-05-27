// 递减元素使数组呈锯齿状
#include <bits/stdc++.h>
using namespace std;

class Solution { // 只有两种情况
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if(!nums.size()) return 0;
        int res1 = 0;
        int res2 = 0;
        vector<int> Temp = nums;
        // 分别以0，1位置为高点
        for(size_t i = 1; i < Temp.size(); i++){
            if(i&1){ // 低点
                int low = Temp[i-1]-1;
                if(i+1<Temp.size()){
                    low = min(Temp[i-1], Temp[i+1]) - 1;
                }
                if(Temp[i]<=low) continue;
                res1 += Temp[i]-low;
                Temp[i] = low;
            }
        }
        Temp = nums;
        if(nums[0] >= nums[1]){
            res2 += nums[0]-nums[1]+1;
        }
        for(size_t i = 1; i < Temp.size(); i++){
            if(i%2==0){ // 低点
                int low = Temp[i-1]-1;
                if(i+1<Temp.size()){
                    low = min(Temp[i-1], Temp[i+1]) - 1;
                }
                if(Temp[i]<=low) continue;
                res2 += Temp[i]-low;
                Temp[i] = low;
            }
        }
        cout << res1 << " " << res2 << endl;
        return min(res1, res2);
    }
};

int main(){
    Solution sol;
    vector<int> vec = {9,6,1,6,2};
    cout << sol.movesToMakeZigzag(vec) << endl;
    return 0;
}