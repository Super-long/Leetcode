#include <bits/stdc++.h>
using namespace std;
/* 
class Solution {
public:
    vector<int> countBits(int num) {
        deque<int> que;
        vector<int> res;
        que.push_back(0);
        que.push_back(1);
        que.push_back(1);
        que.push_back(2);
        int index = 0;
        int base = 4;
        while(index <= num){
            int len = que.size();
            for(int i = base; i < len && index <= num; ++i){
                res.push_back(que[i]);
                que.push_back(que[i] + 1);
                index++;
            }
            base *= 2;
        }
        return res;
    }
}; */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int index = 1;
        int base = 1;
        while(index <= num){
            for (size_t i = 0; i < base && index <= num; i++){
                dp[index] = dp[index - base] + 1;
                index++;
            }
            base *= 2;
        }
        return dp;
    }
};
int main(){
    Solution sol;
    auto vec = sol.countBits(15);
    for(auto x : vec) cout << x << " ";
    return 0;
}