// 括号生成
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        res.reserve(200);
        dfs("", n, res, 0, 0);
        return res;
    }
    void dfs(const string& str, int n, vector<string>& res, int lhs, int rhs){
        if(str.size() == n * 2){
            res.push_back(str);
            return;
        }
        // 保证序列有效时插入
        if(lhs < n){
            dfs(str + '(', n, res, lhs+1, rhs);
        }
        if(rhs < lhs){ // 右括号少于左括号
            dfs(str + ')', n, res, lhs, rhs+1);
        }
    }
};

int main(){
    Solution sol;
    auto res = sol.generateParenthesis(3);
    for(auto item : res){
        cout << item << endl;
    }
    return 0;
}