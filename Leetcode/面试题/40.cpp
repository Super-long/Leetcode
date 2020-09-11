#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int>& candidates, int index, vector<int>& item, int target){
        if(target < 0){
            return;
        } else if (!target){
            res.push_back(item);
            return;
        }
        if(index >= candidates.size()) return;

        for (int i = index; i < item.size(); i++){
            item.push_back(candidates[i]);
            dfs(candidates, i, item, target-candidates[i]);
            item.pop_back();    
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec(candidates.size());
        dfs(candidates, 0, vec, target);
        return res;
    }
};