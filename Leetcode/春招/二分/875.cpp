#include <bits/stdc++.h>
using namespace std; 

class Solution {    // 非常经典，简单的一道二分答案
private:
    bool check(vector<int>& piles, int H, int K){
        if(K == 0) return false;
        int num = 0;
        for(auto x : piles){
            num += (x - 1) / K + 1; // 向上取整;这里有个坑，K可能等于零
        }
        if(num <= H) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int lhs = 0;
        int rhs = INT_MAX;
        int ans = rhs;
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            cout << mid << endl;
            if(check(piles, H, mid)){
                ans = mid;
                rhs = mid - 1;
            } else {
                lhs = mid + 1;
            }
        }   // 不存在没有答案的情况
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {312884470};
    cout << sol.minEatingSpeed(vec, 968709470) << endl;
    return 0; 
}