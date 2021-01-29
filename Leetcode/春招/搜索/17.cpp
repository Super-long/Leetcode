#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> res;    
    void dfs(string digits, string now, int index){
        if(index >= digits.size()) return;
        string base = phoneMap[digits[index]];
        for (size_t i = 0; i < base.size(); i++){
            if(index == digits.size() - 1){
                res.push_back(now + base[i]);
            } else {
                dfs(digits, now + base[i], index + 1);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        dfs(digits, "", 0);
        return res;
    }
};

int main(){
    Solution sol;
    auto item = sol.letterCombinations("234");
    for(auto x : item) cout << x << endl;
    return 0;
}