// 最长公共前缀
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int Min = 0x3f3f3f3f;
        if(!strs.size()) return "";
        for(size_t i = 0; i < strs.size(); i++){
            if(strs[i].size() < Min){
                Min = strs[i].size();
            }
        }
        string res;
        for(size_t i = 0; i < Min; i++){
            char Temp = strs[0][i];
            for(size_t j = 0; j < strs.size(); j++){
                if(strs[j][i] != Temp){
                    return res;
                }
            }
            res.push_back(Temp);
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"dog","racecar","car"};
    cout << sol.longestCommonPrefix(vec) << endl;
    return 0;
}