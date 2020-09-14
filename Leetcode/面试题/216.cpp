#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    int expected;
    // 深度；剩余目标大小；目前下标
    void dfs(int depth, int target, int index, vector<int>& item){
        if(target < 0){
            return;
        }else if(!target && depth == expected+1){
            res.push_back(item);
            return;
        }
        if(depth >= expected+1) return;
        if(index > 9) return;
        for(int i = index; i <= 9; ++i){
            item.push_back(i);
            dfs(depth + 1, target - i, i + 1, item);
            item.pop_back();
            if(target - i < 0) break;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> item;
        expected = k;
        dfs(1, n, 1, item);
        return res;
    }
};