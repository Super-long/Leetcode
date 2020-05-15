// 字典序排数
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MaxValue;
    
    void dfs(int base, vector<int>& res, int x){
        if(base == 0) return;
        for(int i = 0; i < 10; i++){
            int val = base*10*x + i;
            //cout << val << endl;
            if(val > MaxValue) return;
            res.push_back(val);
            dfs(val, res, 1);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        res.reserve(n);
        MaxValue = n;
        dfs(1, res, 0);
/*         for(int i = 1; i < 10; i++){
            dfs(i, res, 0);
        } */
        res.erase(res.begin(), ++(res.begin()));
        return res;
    }
};

int main(){
    Solution sol;
    auto res = sol.lexicalOrder(13);
    for(auto x : res){
        cout << x << " ";
    }
    putchar('\n');
    return 0;
}