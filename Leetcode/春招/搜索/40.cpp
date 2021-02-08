#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<bool> used;
    void dfs(vector<int>& candidates, int target, int index){
        if(target == 0){
            result.push_back(path);
            return;
        }
        if(index >= candidates.size()) return;

        for (size_t i = index; i < candidates.size(); i++){
            if(i != 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;
            if(target - candidates[i] >= 0){
                used[i] = true;
                path.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                path.pop_back();
                used[i] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        used.resize(candidates.size(), false);
        dfs(candidates, target, 0);
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {10,1,2,7,6,1,5};
    auto res = sol.combinationSum2(vec, 8);
    cout << "result : \n";
    for(auto item : res){
        for(auto x : item){
            cout << x << " ";
        }
        putchar('\n');
    }
    return 0;
}