// 每日温度
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T){ // 单调栈
        deque<int> que;
        if(!T.size()) return {};
        que.push_back(0);
        vector<int> res(T.size());
        for(size_t i = 1; i < T.size(); i++){
            while(que.size() && T[i] > T[que.back()]){
                res[que.back()] = i-que.back();
                que.pop_back();
            }
            que.push_back(i);
        }
        for(auto x : que){
            res[x] = 0;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec= {73, 74, 75, 71, 69, 72, 76, 73};
    auto x = sol.dailyTemperatures(vec);
    for(auto y : x){
        cout << y << " ";
    }
    putchar('\n');
    return 0;
}