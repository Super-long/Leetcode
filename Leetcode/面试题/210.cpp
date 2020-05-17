// 课程表II 
#include <bits/stdc++.h>
using namespace std;

// 这个题不严谨 没有考虑自环,和缺少n的情况,当然题目也可以看出不会出现第二种情况
class Solution { // 简单拓扑排序
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mp;
        vector<int> inDegree;
        vector<int> res;

        inDegree.resize(numCourses);
        mp.resize(numCourses);

        for(const auto& item : prerequisites){
            mp[item[1]].push_back(item[0]);
            inDegree[item[0]]++;
        }

        queue<int> que;
        for(int i = 0; i < numCourses; ++i){
            if(inDegree[i] == 0) que.push(i);
        }

        while(que.size()){
            int top = que.front();
            res.push_back(top);
            que.pop();
            for(int i=0;i<mp[top].size();++i){
                inDegree[mp[top][i]]--;
                if(inDegree[mp[top][i]] == 0){
                    que.push(mp[top][i]);
                }
            }
        }
        if(res.size() != numCourses) return vector<int>();
        return res;
    }
};