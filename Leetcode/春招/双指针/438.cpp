#include <bits/stdc++.h>
using namespace std;

class Solution {
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
};

int main(){
    Solution sol;
    auto vec = sol.findAnagrams("cbaebabacd", "abc");
    for(auto x : vec){
        cout << x << endl;
    }
    return 0;
}