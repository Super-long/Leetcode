// 最小覆盖子串
#include <bits/stdc++.h>
using namespace std;

class Solution { // 写的奇慢无比
private:
    unordered_map<char, int> res,mp;
public:
    bool check(){
        for(const auto& x : res){
            //cout << x.first << " " << x.second << endl;
            if(x.second < mp[x.first])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        res.clear();
        for(auto x : t){
            mp[x]++;
            res[x] = 0;
        }
        bool flag = false; //当前是否有解
        int len = 0x3f3f3f3f;
        int lhs = 0, rhs = 0;
        int res_lhs = 0, res_rhs = 0;
        if(res.find(s[rhs]) != res.end())
            res[s[rhs]]++;
        while(rhs < s.size() && lhs <= rhs){
            if(check()){
                if(rhs-lhs+1<len){
                    res_lhs = lhs;
                    res_rhs = rhs;
                    len = res_rhs-res_lhs+1;
                    //cout << s.substr(res_lhs, res_rhs-res_lhs+1) << endl;
                    flag = true;
                }
                if(res.find(s[lhs]) != res.end())
                    res[s[lhs]]--;
                lhs++;
            }else {
                rhs++;
                if(res.find(s[rhs]) != res.end())
                    res[s[rhs]]++;
            }
        }
        while(res_lhs <= res_rhs){
            if(check()){
                if(res.find(s[res_lhs]) != res.end())
                    res[s[res_lhs]]--;
                res_lhs++;
            }else break;
        }
        if(!flag) return "";
        return s.substr(res_lhs, res_rhs-res_lhs+1);
    }
};

int main(){
    Solution sol;
    cout << sol.minWindow("cabwefgewcwaefgcf","cae") << endl;
    return 0;
}