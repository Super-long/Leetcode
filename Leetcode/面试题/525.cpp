//连续数组
#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> vec;
        vec.resize(nums.size()+1);
        vec[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            if(nums[i-1] == 0){
                vec[i] = vec[i-1] - 1;
            } else {
                vec[i] = vec[i-1] + 1;   
            }
        }
        for(auto x: vec){
            cout << x << endl;
        }
        putchar('\n');
        unordered_map<int, int> mp;
        int result = 0;
        for(int i = 0; i < vec.size(); ++i){
            if(mp.find(vec[i]) != mp.end()){
                result = max(result, i-mp[vec[i]]);
            }else {
                mp[vec[i]] = i;
            }
        }
        return result;
    }
}; */

class Solution {
public:
    int findMaxLength(vector<int>& nums) { // 和我思路一样 但是代码像诗一样
        map<int, int> m{{0, -1}};
        int s = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += (nums[i] == 0) ? -1 : 1;
            if (m.count(s)) res = max(res, i - m[s]);
            else m[s] = i;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {0,0,1,0,0,0,1,1};
    cout << sol.findMaxLength(vec) << endl;
    return 0;
}