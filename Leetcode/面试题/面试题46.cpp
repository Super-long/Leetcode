// 把数字翻译成字符串
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int translateNum(int num) { // 好题
        string str = to_string(num);
        str = '0' + str;
        vector<int> dp(str.size(), 0);
        dp[0] = 1;
        for(size_t i = 1; i < str.size(); i++){
            dp[i] += dp[i-1];
            if(str[i-1] != '0' && (str[i-1] - '0') * 10 + (str[i] - '0') <= 25){
                dp[i] += dp[i-2];
            }
        }
        return dp[str.size()-1];
    }
};