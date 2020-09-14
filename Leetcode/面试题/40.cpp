#include <bits/stdc++.h>
using namespace std;

/* class Solution {    // 无法去重
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

        for (int i = index; i < candidates.size(); i++){
            item.push_back(candidates[i]);
            dfs(candidates, i+1, item, target-candidates[i]);
            item.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec;
        dfs(candidates, 0, vec, target);
        return res;
    }
}; */

class Solution {    // 出现重复的关键就是在同一层上会出现相同的值
private:
    vector<vector<int>> res;
    void dfs(int index, vector<int>& candidates, vector<int>& item, int target, vector<bool>& judge){
        if(target < 0){
            return;
        } else if(target == 0){
            res.push_back(item);
            return;
        }

        for(int i = index; i < candidates.size(); ++i){
            if(i > 0 && candidates[i] == candidates[i-1] && judge[i-1] == false){
                continue;
            }
            item.push_back(candidates[i]);
            judge[i] = true;
            dfs(i+1, candidates, item, target-candidates[i], judge);
            judge[i] = false;
            item.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        vector<bool> judge(candidates.size(), false);
        dfs(0, candidates, vec, target, judge);
        return res;
    }
};