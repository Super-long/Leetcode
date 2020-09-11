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
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        vector<string> result;
        dfs(result, "", digits, 0);
        return result;
    }

    void dfs(vector<string>& result, string str, string digits ,int index){
        if(str.size() == digits.size()){
            result.push_back(std::move(str));
            return;
        }
        if(index >= digits.size()) return;
        string temp = phoneMap[digits[index]]; 
        for (int i = 0; i < temp.size(); i++){
            str.push_back(temp[i]);
            dfs(result, str, digits, index + 1);
            str.pop_back();
        }
        return;
    }
};

int main(){
    Solution sol;
    auto x = sol.letterCombinations("234");
    for(auto item : x){
        cout << item << endl;
    }
    return 0;
}