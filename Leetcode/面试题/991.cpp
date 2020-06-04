// 坏了的计算器
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X) {
            ans++;
            if (Y % 2 == 1)
                Y++;
            else
                Y /= 2;
        }
        return ans + X - Y;
    }
};

int main(){
    Solution sol;
    cout << sol.brokenCalc(5, 8);
    return 0;
}