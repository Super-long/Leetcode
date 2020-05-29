// 字母大小写全排列
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        dfs(S, 0, res);
        return res;
    }
    void dfs(string S, int index, vector<string>& res){
        if(index == S.size()){
            res.push_back(S);
            return;
        }
        if(isalpha(S[index])){
            S[index] = tolower(S[index]);
            //res.push_back(S);
            dfs(S, index+1, res);
            S[index] = toupper(S[index]);
            //res.push_back(S);
            dfs(S, ++index, res);
        }else {
            dfs(S, index+1, res);
        }
    } 
};
int main(){
    Solution sol;
    string str = "a1b2";
    auto res = sol.letterCasePermutation(str);
    for(auto x : res){
        cout << x << endl;
    }
    return 0;
}