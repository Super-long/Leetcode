// 3的幂
#include <bits/stdc++.h>
using namespace std;

class Solution {
public: // 1162261467为3的19次方 
    bool isPowerOfThree(int n) {
        if(n > 0 && 1162261467%n == 0)
            return true;
        return false;
    }
};

int main(){
    Solution sol;
    cout << sol.isPowerOfThree(27) << endl;
    return 0;
}