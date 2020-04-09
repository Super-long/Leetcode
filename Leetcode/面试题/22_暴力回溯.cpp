// 括号生成
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
bool vaild(const string& str){ // 暴力
    int res = 0;
    for(auto x : str){
        if(x == '(') ++res;
        else --res;
        if(res < 0) return false;
    }
    return (res == 0);
}
int length;
vector<string> pool;
public:
    vector<string> generateParenthesis(int n) {
        pool.clear();        
        if(!n) return pool;
        this->length = n*2;
        dfs("");
        return pool;
    }

    void dfs(const string& str){
        //if(!vaild(str)) return;
        if(str.size() == length){
            if(vaild(str))
                pool.push_back(str);
            return;
        }
        dfs(str+'(');
        dfs(str+')');
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