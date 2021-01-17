#include <bits/stdc++.h>
using namespace std;

class Solution {    // 经典题目，容易写崩 
public:
    unordered_map <char, int> ori, cnt;

    bool check() {
        for (const auto &p: ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (const auto &c: t) {
            ++ori[c];
        }

        int len = 0x3f3f3f3f;
        int l = 0, r = -1;
        int lhs = -1;
        while(r < static_cast<int>(s.size())){  // 踩坑了
            if(ori.find(s[++r]) != ori.end()){
                cnt[s[r]]++;
            }

            while(check() && l <= r){
                if(r - l + 1 < len){
                    len = r - l + 1;
                    lhs = l;
                }
                if(ori.find(s[l]) != ori.end()){
                    cnt[s[l]]--;
                }
                ++l;
            }
        }

        return lhs == -1 ? "" : s.substr(lhs, len);
    }
};

int main(){
    Solution sol;
    cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}