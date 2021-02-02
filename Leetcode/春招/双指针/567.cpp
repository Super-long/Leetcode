#include <bits/stdc++.h>
using namespace std;

/* class Solution {
private:
    unordered_map<char, int> ori, cnt;
public:
    bool checkInclusion(string s1, string s2) { 
        for(auto x : s1){
            ori[x]++;
        }
        int lhs = 0, rhs = 0;
        int vaild = 0;
        while(rhs < s2.size()){
            char c = s2[rhs++];
            if(ori.find(c) != ori.end()){
                cnt[c]++;
                if(cnt[c] == ori[c]){
                    vaild++;
                }
            }

            while(rhs - lhs >= s1.size()){ // 收缩的条件
                if(vaild == ori.size()) return true;

                char d = s2[lhs];
                ++lhs;
                if(ori.find(d) != ori.end()){
                    if(cnt[d] == ori[d]){
                        vaild--;
                    }
                    cnt[d]--;
                }
            }
        }
        return false;
    }
}; */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        int lhs = 0;
        int rhs = 0;
    
        unordered_map<char, int> vis1;
        for(auto x : s1) vis1[x]++;
        int vaild = 0;
        unordered_map<char, int> vis2;

        while(rhs < len2){
            if(vis1.find(s2[rhs]) != vis1.end()){
                vis2[s2[rhs]]++;
                if(vis2[s2[rhs]] == vis1[s2[rhs]]) vaild++;
            } else {
                lhs = rhs = rhs + 1;
                vaild = 0;
                vis2.clear();
                continue;
            }

            while(rhs - lhs + 1 >= len1){   // 这里遇到的都是包含在s1中的字符
                if(vaild == vis1.size()) return true;
                char ch = s2[lhs];
                if(vis1[ch] == vis2[ch]){
                    vaild--;
                }
                vis2[ch]--;
                lhs++;
            }
            rhs++;
        }
        return false;
    }
};

int main(){
    Solution sol;
    cout << sol.checkInclusion("ab", "eidboaoo") << endl;
    return 0;
}