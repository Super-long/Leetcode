// 总持续时间可被 60 整除的歌曲
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& Time) {
        unordered_map<int,int> mp;
        for(auto& x : Time){
            x%=60;
            mp[x]++;
        }
        int res = 0;
        for(auto x : Time){ // mp中存在的值总在自身索引的右侧
            mp[x]-=1;
            if(mp[(60-x)%60] > 0){    // 取余防止值为零
                res += mp[(60-x)%60];
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {30,20,150,100,40};
    cout << sol.numPairsDivisibleBy60(vec) << endl;
    return 0;
}