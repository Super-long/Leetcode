#include <bits/stdc++.h>
using namespace std;

/* class Solution {
private:
    unordered_map<char, int> ori, cnt;
    vector<int> res;
public:
    vector<int> findAnagrams(string p, string s){
        for (size_t i = 0; i < s.size(); i++){
            ori[s[i]]++;
        }
        
        int lhs = 0, rhs = 0;
        int vaild = 0;

        while(rhs < p.size()){
            char ch = p[rhs++];
            if(ori.find(ch) != ori.end()){
                cnt[ch]++;
                if(cnt[ch] == ori[ch]){
                    vaild++;
                }
            }

            //cout << lhs << " " << rhs << " " << s.size() <<endl;
            while(rhs - lhs >= s.size()){
                //cout << vaild <<endl;
                if(vaild == ori.size()){
                    res.push_back(lhs);
                }
                char c = p[lhs];
                if(ori.find(c) != ori.end()){
                    if(cnt[c] == ori[c]){
                        vaild--;
                    }
                    cnt[c]--;
                }
                lhs++;
            }
        }
        return std::move(res);
    }
}; */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lhs = 0;
        int rhs = 0;
        unordered_map<char, int> vis_s;
        unordered_map<char, int> vis_p;
        int vaild = 0;
        vector<int> res; 

        auto check = [&](char ch){  // 建立在vis_p中已经找到了ch
            vis_s[ch]++;
            if(vis_s[ch] == vis_p[ch]) {
                vaild++;
            }  
        };

        auto inc = [&](char ch){
            if(vis_s[ch] == vis_p[ch]){
                vaild--;
            }
            vis_s[ch]--;
        };

        for(auto x : p) vis_p[x]++;

        while(lhs < s.length()) {
            char chT = s[rhs];
            if(vis_p.find(chT) != vis_p.end()) {
                check(chT);
            } else {
                lhs = rhs = rhs + 1;
                vaild = 0;
                vis_s.clear();
                continue;
            }
            while(rhs - lhs +1 == p.size()){    // 这里可以保证区间内字符都存在与p中
                if(vaild == vis_p.size()) res.push_back(lhs);
                inc(s[lhs]);
                lhs++;
            }
            rhs++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    auto vec = sol.findAnagrams("abab", "ab");
    for(auto x : vec){
        cout << x << endl;
    }
    return 0;
}