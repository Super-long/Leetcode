//验证回文字符串 Ⅱ
#include <bits/stdc++.h>
using namespace std;

//加一句这个可以提速百分之60 比赛常用 没想到力扣也可以这么玩
static int n=[](){std::ios::sync_with_stdio(false);std::cin.tie(nullptr);return 0;}();

class Solution {
private:
    bool palindrome(const std::string& s, int i, int j)
    {
        for ( ; i < j && s[i] == s[j]; ++i, --j);
        return i >= j;
    }
public:
    bool validPalindrome(string s) {
        if(!s.size()) return true;
        int lhs = 0, rhs = s.size()-1;
        while(lhs < rhs){
            if(s[lhs]==s[rhs]){
                lhs++;
                rhs--;
            } else {
                return palindrome(s, lhs , rhs-1) || palindrome(s, lhs+1,rhs);
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    cout << sol.validPalindrome("deeee") << endl;
    return 0;
}