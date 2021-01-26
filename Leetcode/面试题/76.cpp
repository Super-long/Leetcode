// 最小覆盖子串
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 写的奇慢无比
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
}; */

class Solution {    // 做双指针就一招，想清楚什么i时候左边窗口移动就好
private:
    unordered_map<char, int> vis;
    bool check(unordered_map<char, int>& mp){
        for(const auto& x :vis){
            if(x.second > mp[x.first]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        for(auto x : t){
            vis[x]++;
        }

        unordered_map<char, int> mp;
        int lhs = 0;    // 在s上滑动
        int rhs = 0;
        int res = INT_MAX;
        int res_lhs = -1;

        while(rhs < s.size()){
            if(vis.find(s[rhs]) != vis.end()){
                mp[s[rhs]]++;
            }
            if(check(mp) && lhs <= rhs){  // 目前窗口满足条件
            cout << lhs << " " << rhs << endl;
                do{
                    if(rhs - lhs + 1 < res){
                        res = rhs - lhs + 1;
                        res_lhs = lhs;
                    }
                    if(vis.find(s[lhs]) != vis.end()){
                        mp[s[lhs]]--;
                    }
                    lhs++;
                }while(check(mp) && lhs <= rhs); 
            }
            rhs++;
        }
        cout << res << " " << res_lhs << endl;
        return res_lhs == -1 ? "" : s.substr(res_lhs, res);
    }
};

int main(){
    Solution sol;
    cout << sol.minWindow("a","a") << endl;
    return 0;
}