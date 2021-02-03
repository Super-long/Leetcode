#include <bits/stdc++.h>
using namespace std;

/* class Solution {
vector<vector<int>> res;
vector<int> path;
private:
    void dfs(int index, int target, vector<int>& candidates){
        if(target == 0){
            res.push_back(path);
            return;
        } else if(target < 0 || index >= candidates.size()) {
            return;
        }
        int len = target/ candidates[index];   // 向上取整

        for (size_t i = 1; i <= len; i++){   // 此数出现的次数
            for (size_t j = index; j < candidates.size(); j++){ // 第几个数
                if(i * candidates[j] <= target){
                    for (size_t k = 0; k < i; k++){
                        cout << candidates[j] << " ";
                        if(candidates[j] == 5) cout << "j == 5 : " << i << " " << j << " " <<k << endl;
                        path.push_back(candidates[j]);
                    }
                    putchar('\n');
                }
                dfs(j + 1, target - i * candidates[j] , candidates);

                if(i * candidates[j] <= target){
                    for (size_t k = 0; k < i; k++){
                        path.pop_back();
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(0, target, candidates);
        return res;
    }
}; */

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        dfs(candidates, target, ans, combine, idx + 1); // 不选择这个数

        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {2,3,5};
    auto res = sol.combinationSum(vec, 8);
    cout << "result : \n";
    for(auto item : res){
        for(auto x : item){
            cout << x << " ";
        }
        putchar('\n');
    }
    return 0;
}