// 每个元音包含偶数次的最长子字符串
#include <bits/stdc++.h>
using namespace std;

// 每个元音字母，即 'a'，'e'，'i'，'o'，'u' ，在子字符串中都恰好出现了偶数次 注意是都
/* class Solution { // 瞎写一通
public:
    int findTheLongestSubstring(string s) {
        int dp[500000+10];
        memset(dp, 0, sizeof dp);
        int letter[26];
        memset(letter, 0, sizeof letter);
        int res = 0;
        if(s[0]!='a' && s[0]!='e' && s[0]!='i' && s[0]!='o' && s[0]!='u'){
            dp[0] = 1;
        }else {
            dp[0]=0;
        }
        for(int i = 1; i < s.size(); i++){
            if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
                dp[i] = dp[i-1]+1;
                continue;
            }
            if(letter[s[i]-97]&1){ // 原音
                dp[i] = dp[i-1]+1;
            }else {
                dp[i] = dp[i-1];
            }
            letter[s[i]-97]++;
        }
        for(size_t i = 0; i < s.size(); i++){
            cout << dp[i] << " ";
        }
        putchar('\n');
        
        return dp[s.size()-1];
    }
}; */

class Solution { // 太巧妙了 前缀和与状态压缩 好题
public:
    int findTheLongestSubstring(string s) {
        int ans = 0, status = 0;
        vector<int> vec(1<<5, -1);
        vec[0] = 0; //所有值出现0次
        for(int i = 0; i < s.size(); ++i){
            if (s[i] == 'a') {
                status ^= 1<<0;
            } else if (s[i] == 'e') {
                status ^= 1<<1;
            } else if (s[i] == 'i') {
                status ^= 1<<2;
            } else if (s[i] == 'o') {
                status ^= 1<<3;
            } else if (s[i] == 'u') {
                status ^= 1<<4;
            } 
            if(vec[status] != -1){
                ans = max(ans, i + 1 - vec[status]);// 比如7 9 我们需要的是[8,9]
            } else {
                vec[status] = i + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string str = "eleetminicoworoep";
    cout << sol.findTheLongestSubstring(str) << endl;
    return 0;
}