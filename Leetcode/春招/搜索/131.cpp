#include <bits/stdc++.h>
using namespace std;

/* class Solution {
private:
    vector<vector<string>> res;
    vector<string> bucket;

    bool check(const string& s, int lhs, int rhs){
        while(lhs <= rhs){
            if(s[lhs] == s[rhs]){
                lhs++;
                rhs--;
            } else {
                return false;
            }
        }
        return true;
    }

    void dfs(const string& s, int index){
        if(index > s.size()) return;
        if(index == s.size()){
            res.push_back(bucket);
            return;
        }

        for (size_t i = index; i < s.size(); i++){
            if(check(s, index, i)){
                bucket.push_back(s.substr(index, i - index + 1));
                dfs(s, i + 1);
                bucket.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
}; */

class Solution {
private:
    vector<vector<string>> res;
    vector<string> bucket;
    bool check(string& s, int lhs, int rhs){
        while(lhs <= rhs){
            if(s[lhs] != s[rhs]) return false;
            lhs++;
            rhs--;
        }
        return true;
    }

    void dfs(string& str, int index){
        if(index > str.size()) return;
        if(index == str.size()){
            res.push_back(bucket);
            return;
        }

        for (size_t i = index; i < str.size(); i++){
            if(check(str, index, i)){
                bucket.emplace_back(str.substr(index, i - index + 1));
                dfs(str, i + 1);
                bucket.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }
};

int main(){
    Solution sol;
    auto x = sol.partition("aabb");
    for(auto item : x){
        for(auto y : item){
            cout << y << " ";
        }
        putchar('\n');
    }
    return 0;
}

