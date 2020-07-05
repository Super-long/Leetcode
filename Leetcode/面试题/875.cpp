// 爱吃香蕉的珂珂
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(vector<int>& piles, int mid, int H){
        int sum = 0;
        for(auto x : piles){
            sum += (x + mid - 1) / mid;
        }
        return sum <= H;
    }
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = 1000000000;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(piles, mid, H)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

