#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 中心扩展    // 两个循环 
public:
    int countSubstrings(string s) {
        int sum = s.size(); // 每一个字母都是一个回文串
        for (size_t i = 0; i < s.size(); i++){
            int lhs = i-1;  // 枚举奇数
            int rhs = i+1;
            while(lhs >= 0 && rhs < s.size()){
                if(s[lhs] == s[rhs]){
                    sum++;
                    --lhs;
                    ++rhs;
                }else {
                    break;
                }
            }
        }
        if(s.size() == 1) return sum;
        for (size_t i = 0; i < s.size()-1; i++){
            int midl = i;
            int midr = i + 1;
            while(midl >= 0 && midr < s.size()){
                if(s[midl] == s[midr]){
                    sum++;
                    --midl;
                    ++midr;
                }else {
                    break;
                }
            }
        }
        return sum;
    }
}; */

// https://leetcode-cn.com/problems/palindromic-substrings/solution/hui-wen-zi-chuan-by-leetcode-solution/
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < 2 * n - 1; ++i) {
            int l = i / 2, r = i / 2 + i % 2;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.countSubstrings("aaa") << endl;
    return 0;
}