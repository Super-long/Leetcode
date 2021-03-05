#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int>> input;
        for(auto item : envelopes) {
            input.emplace_back(make_pair(item[0], item[1]));
        }
        sort(input.begin(), input.end(), [](const auto& e1, const auto& e2) -> bool {
            return e1.first < e2.first || (e1.first == e2.first && e1.second > e2.second);
        }); // 这里排序是最难想到的，在first相等的时候怎么做是最麻烦的

        vector<int> array;
        for(auto item : input) {
            array.push_back(item.second);
        }

        vector<int> res;
        for (size_t i = 0; i < array.size(); i++){
            int lhs = 0;
            int rhs = res.size() - 1;
            int ans = res.size();
            while(lhs <= rhs){
                int mid = lhs + (rhs - lhs) / 2;// 就是找大于等于的第一个数
                if(res[mid] < array[i]){
                    lhs = mid + 1;
                } else {
                    ans = mid;
                    rhs = mid - 1;
                }
            }
            if(ans == res.size()){
                res.push_back(array[i]);
            } else {
                res[ans] = array[i];
            }
        }
        return res.size();
    }
};


int main(){
    Solution sol;
    vector<vector<int>> res = {
        {5,4},
        {6,4},
        {6,7},
        {2,3}
    };
    auto temp = sol.maxEnvelopes(res);
    cout << temp <<  endl;
    return 0;
}