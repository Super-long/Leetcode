// 转变数组后最接近目标值的数组和
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        if(!arr.size()) return 0;
        vector<int> vec(arr.size(), 0);
        sort(arr.begin(), arr.end());
        vec[0] = arr[0];
        for(size_t i = 1; i < arr.size(); i++){
            vec[i] = vec[i-1] + arr[i];
        }
        int lhs = target/arr.size();
        for(size_t i = 0; i < arr.size()-1; i++){
            if(lhs < arr.size() && )
        }
        
        int rhs = arr.size();
        for(; lhs <= rhs; lhs++){
            if(vec[])
        }
    }
};

