// 矩阵快速幂
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    double quickMul(double x, long long N){
        if(N == 0){
            return 1;
        }
        double res = quickMul(x, N/2);
        return N&1 ? res*res*x : res*res;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

int main(){
    Solution sol;
    cout << sol.myPow(5,-1) << endl;
    return 0;
}