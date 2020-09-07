#include <bits/stdc++.h>
using namespace std;

class Solution {
// 其实就是找一个公共前缀
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while(m < n){
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;  // 不用1是因为防止零的情况
    }
};

int main(){
    Solution sol;
    cout << sol.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}