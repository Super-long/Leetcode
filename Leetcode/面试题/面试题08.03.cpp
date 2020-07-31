// 魔术索引
#include <bits/stdc++.h>
using namespace std;

/* class Solution { 
public:
    int findMagicIndex(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size();){
            cout << i << endl;
            if(nums[i] == i){
                return i;
            }else if(nums[i] > i){
                i = nums[i];
            }else {
                ++i;
            }
        }
        return -1;
    }
}; */

class Solution { // 分治
private:
    int getAnswer(vector<int>& nums, int lhs, int rhs){
        if(lhs > rhs){
            return -1;
        }
        int mid = (lhs + rhs) / 2;
        int res = getAnswer(nums, lhs, mid - 1);
        if(res != -1){
            return res;
        }else if(mid == nums[mid]){
            return mid;
        }
        return getAnswer(nums, mid + 1, rhs);
    }
public:
    int findMagicIndex(vector<int>& nums) {
        return getAnswer(nums, 0, nums.size() - 1);
    }
};

int main(){
    Solution sol;
    vector<int> vec = {-531369933, -469065528, -430059048, -428981853, -319235969, -288076332, -286667432, -282312559, -197049680, -197022263, -174416117, -138027773, -121899023, -111631966, -107567458, -70437707, -52463072, -45519851, -38641451, -15825815, -3835472, -1525043, 22, 566842886, 593757472, 605439236, 619794079, 640069993, 657657758, 718772950, 815849552, 839357142, 936585256, 1006188278, 1042347147, 1057129320, 1062178586, 1069769438};
    cout << sol.findMagicIndex(vec) << endl;
    return 0; 
}