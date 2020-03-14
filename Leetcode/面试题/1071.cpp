//字符串最大公因子
/*
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int gcd(int l, int r){
        return r == 0 ? l : (gcd(r, l%r));
    }
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1) return "";
        int lhs = str1.length();
        int rhs = str2.length();
        return str1.substr(0, gcd(lhs, rhs));
    }
};

int main(){
    Solution res;
    cout << res.gcdOfStrings("ABCABC", "ABC") << endl;
    return 0;
}