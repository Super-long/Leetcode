// 连通网络的操作次数
#include <bits/stdc++.h>
using namespace std;

class Solution {// 求联通块
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> result; // size是联通块数目 其值存的是内部的块数
        vector<vector<int>> mp;
        mp.resize(n);
        int flag[100000+10];
        memset(flag, 0 ,sizeof flag);
        for(const auto& item: connections){
            mp[item[0]].push_back(item[1]);
            mp[item[1]].push_back(item[0]);
        }
        for(int i=0;i<n;++i){
            if(flag[i]) continue;
            queue<int> que;
            int sum = 1;
            que.push(i);
            flag[i] = 1;
            while(que.size()){
                int Top = que.front();
                que.pop();
                for(auto item : mp[Top]){
                    if(!flag[item]){ // 未被遍历的节点
                        que.push(item);
                        flag[item] = 1;
                        sum++;
                    }
                }
            }
            result.push_back(sum);
        }
        int N = result.size(); // 联通块的数量
        cout << "连通块:" << N << endl;
        int M = 0;
        for(auto x : result){
            //cout << x << endl; 
            M += (x-1);
        }
        if(connections.size()-M >= N-1) return N-1;
        else return -1; 
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec = {
        {0,1},
        {0,2},
        {1,2}
        //{1,2},
        //{1,3}
    };
    cout << sol.makeConnected(4, vec) << endl;
    return 0;
}
