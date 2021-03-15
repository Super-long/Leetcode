#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        for (size_t i = 1; i <= n; i++){
            for (size_t j = 1; j <= i; j++){
                dp[i] = max<int>(dp[i], max<int>(j*(i-j), j * dp[i-j]));
            }
        }
        return dp.back();
    }
};

int main(){
    Solution sol;
    cout << sol.cuttingRope(10) << endl;
    return 0;
}