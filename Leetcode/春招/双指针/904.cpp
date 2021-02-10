#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int lhs = 0;
        int res = INT_MIN;
        unordered_map<int, int> vis;    //可以不使用hash，因为最多两个数，但是写着简单
        for (size_t i = 0; i < tree.size(); i++){
            if(vis.find(tree[i]) != vis.end()){
                res = max<int>(res, i - lhs + 1);
                vis[tree[i]]++;
            } else {
                while(vis.size() >= 2){ // 其实是==，但是不影响正确性
                    vis[tree[lhs]]--;
                    if(vis[tree[lhs]] == 0) vis.erase(tree[lhs]);
                    lhs++;
                }
                vis[tree[i]]++;
                res = max<int>(res, i - lhs + 1);   // 这里理论来说不会更新的
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {3,3,3,1,2,1,1,2,3,3,4};
    cout << sol.totalFruit(vec) << endl;
    return 0;
}