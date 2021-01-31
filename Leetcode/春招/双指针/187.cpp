#include <bits/stdc++.h>
using namespace std;

class Solution {    // 严格来说不是双指针，而且最优解应该是Robin-karp算法，但是后者没有啥记的必要，知道是常数范围内切片就可以了，而且和字符串哈希有相似的地方
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>res;
        for(int i=0;i+9<s.size();i++){
            auto key=s.substr(i,10);
            if(mp[key]==1)res.push_back(key);
            mp[key]++;
        }
        return res;
    }
};
