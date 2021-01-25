#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    bool check(vector<int>& weights, int D, int  k){
        int sum = 0;
        int temp = 0;
        for(auto item : weights){
            if(item + temp <= k){
                temp += item;
            } else {
                sum++;
                temp = item;
            }
        }
        if(temp) sum++;
        return sum <= D;
    }
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int rhs = accumulate(weights.begin(), weights.end(), 0);
        int lhs = *max_element(weights.begin(), weights.end());
        int ans = rhs;
        while(lhs <= rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(check(weights, D, mid)){
                ans = mid;
                rhs = mid - 1;
            } else {
                lhs = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    std::cout << sol.shipWithinDays(vec, 5) << endl;
    return 0;
    }