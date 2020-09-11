#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<int>& candidates, int index, vector<int>& item, int target){
        if(target < 0){
            return;
        } else if (!target){
            cout << index << endl;
            res.push_back(item);
            return;
        }
        item.push_back(candidates[index]);
        dfs(candidates, index, item, target - candidates[index]);
        item.pop_back();

        for (int i = index + 1; i < candidates.size(); i++){
            item.push_back(candidates[i]);
            dfs(candidates, i, item, target - candidates[i]);
            item.pop_back();
        }
        return;
    }
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> item;
        dfs(candidates, 0, item, target);
        return res;
    }
};