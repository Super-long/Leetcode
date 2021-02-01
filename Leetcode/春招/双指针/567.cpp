#include <bits/stdc++.h>
using namespace std;

class Solution {
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
};

int main(){
    Solution sol;
    cout << sol.checkInclusion("abcdxabcde", "abcdeabcdx") << endl;
    return 0;
}