//买股票的最佳时机

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(!prices.size()) return 0;
        int minvalue = prices.front(), ret = 0;
        for(auto item : prices){
            ret = max(ret , item-minvalue);
            minvalue = std::min(minvalue, item);
        }
        return ret;
    }
};

int main(){
    Solution sol;
    vector<int> vec({7,6,4,3,1});
    cout << sol.maxProfit(vec) << endl;
    return 0;
}