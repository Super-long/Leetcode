#include <bits/stdc++.h>
using namespace std;

class Solution {
using PII = pair<int, int>;
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<PII> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const PII& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while(!stk.empty()){
            if(seen.find(stk.top()) != seen.end()){
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());
            auto item = stk.top();
            int remain_x = item.first;
            int remain_y = item.second;
            if(remain_x == z || remain_y == z || remain_x + remain_y == z) return true;
            stk.emplace(remain_x-min(remain_x, y-remain_y), remain_y + min(remain_x, y-remain_y));
            stk.emplace(remain_x+min(remain_y, x-remain_x), remain_y - min(remain_y, x-remain_x));
            stk.emplace(remain_x, y);
            stk.emplace(x, remain_y);
            stk.emplace(0, remain_y);
            stk.emplace(remain_x, 0);
        }
        return false;
    }
};

int main(){
    Solution sol;
    int x,y,z;
    cin >> x >> y >> z;
    cout << sol.canMeasureWater(x, y, z) << endl;
    cin >> x >> y >> z;
    cout << sol.canMeasureWater(x, y, z) << endl;
}