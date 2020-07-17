// 尽可能使字符串相等
#include <bits/stdc++.h>
using namespace std;

// 滑动窗口的模板题,这样的写法很漂亮,
// 先把右边递增到极限,然后缩短左边

class Solution {    
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int ans = 0;
        int lhs = 0;
        int rhs = 0;
        int cost = 0;
        while(rhs < n){
            cost += abs(s[rhs] - t[rhs]);
            while(cost > maxCost){
                cost -= abs(s[lhs] - t[lhs]);
                lhs++;
            }
            ans = max(ans, rhs - lhs + 1);
            rhs++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.equalSubstring("abcd", "bcdf", 3) << endl;
    return 0;
}