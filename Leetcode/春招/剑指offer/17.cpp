#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int temp = pow(10, n) - 1;
        int Max = pow(10, n);
        vector<int> res;
        res.reserve(temp);
        while(temp--){
            res.push_back(Max - temp - 1);
        }
        return res;
    }
};