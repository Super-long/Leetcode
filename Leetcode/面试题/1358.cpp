// 包含所有三种字符的子字符串数目
#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public:
    int numberOfSubstrings(string s) {
        int lhs = 0,rhs = 0;
        int res = 0;
        int flag[3];
        memset(flag, 0, sizeof flag);
        while(rhs< s.size()){
            flag[s[rhs]-97]++;
            if(flag[0] && flag[1] && flag[2]){
                cout << lhs << " " << rhs << endl;
                res += (s.size() - 1) - rhs + 1;
                cout << res << endl;
                flag[s[lhs]-97]--;
                lhs++; 
                //continue;
            }
            rhs++;
        }
        //cout << lhs << endl;
        while(flag[0] && flag[1] && flag[2]){
            //cout << flag[0] << flag[1] << flag[2] << endl;
            res++;
            flag[s[lhs]-97]--;
            lhs++;
        } 
        return res;
    }
}; */
class Solution {
    int cnt[3];
public:
    int numberOfSubstrings(string s) {
        int len=(int)s.length(),ans=0;
        cnt[0]=cnt[1]=cnt[2]=0;
        for (int l=0,r=-1;l<len;){
            while (r<len && !(cnt[0]>=1 && cnt[1]>=1 && cnt[2]>=1)){
                if (++r==len) break;
                cnt[s[r]-'a']++;
            }
            ans+=len-r;
            //cout << l << " " << r << endl;
            //cout << ans << endl;
            cnt[s[l++]-'a']--;
        }
        return ans;
    }
};


int main(){
    Solution sol;
    string s = "acbbcac";
    cout << sol.numberOfSubstrings(s) << endl;
    return 0;
}