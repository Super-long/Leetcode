#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int lhs = 0;
        int rhs = 0;
        int sum = 0;
        int res = INT_MIN;
        while(rhs < t.size()){
            sum += abs(s[rhs] - t[rhs]);
            while(sum > maxCost){
                sum -= abs(s[lhs] - t[lhs]);
                lhs++;
            }
            res = max(res, rhs - lhs + 1);
            cout << lhs << " " << rhs << endl;
            cout << res << endl;
            rhs++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout << sol.equalSubstring("abcd","acde" ,0) << endl;
    return 0;
}