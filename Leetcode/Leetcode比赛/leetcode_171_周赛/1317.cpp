// 将整数转换为两个无零整数的和
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int A = 1; A < n; ++A) {
            int B = n - A;
            if ((to_string(A) + to_string(B)).find('0') == string::npos) {
                return {A, B};
            }
        }
        return {};
    }
};

int main(){
    Solution sol;
    auto x = sol.getNoZeroIntegers(69);
    cout << x[0] << " " << x[1] << endl;
    return 0;
}