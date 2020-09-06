#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(auto x : s){
            if(pairs.count(x)){
                if(stk.empty() || stk.top() != pairs[x]){
                    return false;
                }else {
                    stk.pop();
                }
            }else {
                stk.emplace(x);
            }
        }
        return stk.empty();
    }
};