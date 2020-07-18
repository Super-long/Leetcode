// 在 D 天内送达包裹的能力
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& weights, int num, int D){
        int res = 0;
        int index = 0;
        while(index < weights.size()){
            if(weights[index] > num) return false;  //第一遍忘记了 不加会导致死循环
            if(res + weights[index] <= num){
                res += weights[index];
                index++;
            }else {
                res = 0;
                D--;
            }
        }
        if(res > 0){
            D--;
        }
        return D >= 0;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int lhs = 0;
        int rhs = 25000000 + 10;
        while(rhs - lhs > 1){
            int mid = (lhs + rhs)/2;
            if(check(weights, mid, D)){
                rhs = mid;
            }else {
                lhs = mid;
            }
        }
        return rhs;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,2,3,1,1};
    cout << sol.shipWithinDays(vec, 4) << endl;
    //sol.check(vec, 3, 3);
    return 0;
}