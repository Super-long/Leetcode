#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double dfs(double para, int base){
        if(base == 1) return para;
        if(base&1){
            return dfs(para, base/2) * dfs(para, base/2 + 1);
        } else {
            double temp = dfs(para, base/2);
            return temp * temp;
        }
    }
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        bool flag = false;
        if(n < 0){
            flag = true;
        }
        double res = 0;
        if(n == INT_MIN){
            res = dfs(x, flag ? -(n+1) : n) * x; 
        } else {
            res = dfs(x, flag ? -n : n); 
        }
        return flag ? 1/res : res;
    }
};