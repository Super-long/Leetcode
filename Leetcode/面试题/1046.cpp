// 最后一块石头的重量
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> que;
        for(auto x : stones){
            que.push(x);
        }
        int res = 0;
        while(que.size() >= 2){
            int para1 = que.top(); que.pop();
            int para2 = que.top(); que.pop();
            if(para1 != para2){
                que.push(para1 - para2);
            }
        }
        return que.size() ? que.top() : 0;
    }
};