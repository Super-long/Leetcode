#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i < n){ // 从哪里开始遍历
            int gasnum = 0;
            int costnum = 0;
            int cnt = 0;
            while(cnt < n){
                int j = (cnt + i) % n;
                gasnum += gas[j];
                costnum += cost[j];
                if(gasnum < costnum){
                    break;
                }
                ++cnt;
            }
            if(cnt == n){
                return i;
            }

            i += cnt + 1;   // 这一项pass，下一项
        }

        return -1; // n个全部结束
    }
};