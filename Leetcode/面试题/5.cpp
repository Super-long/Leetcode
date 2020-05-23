//最长回文子串
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
int init(string& a, int len) // 这种填充方式相比于string直接加比较快
{
    int ans=1;
    for(int i=len;i>=0;i--)
    {
        a[2*i+1]='#';
        a[2*i+2]=a[i];
        ans+=2;
    }
    a[0]='$';
    a[ans]='\0';
    return ans;
}

public:
    string longestPalindrome(string s) {
        int p[40000+100];
        memset(p, 0, sizeof p);
        string temp = s;
        int t = s.size();
        s.resize(2*s.size()+10);
        int len = init(s, t);
        cout << s << endl;
        int id = 0, mx = 0;
        int radius = 0, center = 0;
        for(int i=1;i<len;++i){
            p[i] = mx > i ? min(p[2*id-i], mx-i) : 1;
            while(s[i+p[i]] == s[i-p[i]]) p[i]++; // 尝试扩展
            if(mx < i+p[i]){
                mx = i+p[i];
                id = i;
            }
            if(radius < p[i]){
                radius = p[i];
                center = i;
            }
        }
        int lhs = center-radius+1;
        int rhs = center+radius-1;
        string result;
        cout << center << " " << radius << endl;
        for(int i = lhs; i<=rhs;++i){
            if(s[i]!='#' && s[i]!='$'){
                result+=s[i];
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    cout << sol.longestPalindrome("abcdasdfghjkldcba") << endl;
    return 0;
}