// 最小时间差
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int change(string str){
        stringstream s(str);
        int hour = 0;
        int minutes = 0;
        s >> hour;
        char ch;
        s >> ch;
        s >> minutes;
        return hour*60 + minutes;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        if(!timePoints.size()) return 0;
        vector<int> vec;
        for(size_t i = 0; i < timePoints.size(); i++){
            vec.push_back(change(timePoints[i]));
            // 这里有一个可以优化的地方 就是两次调用change直接返回0
        }
        sort(vec.begin(), vec.end());
        int res = INT_MAX;
        for(size_t i = 1; i < vec.size(); i++){
            res = min(res, vec[i] - vec[i-1]);
        }
        return min(res, vec.front() + 1440 - vec.back()); 
    }
};

int main(){
    Solution sol;
    vector<string> vec = {"23:59","00:00"};
    cout << sol.findMinDifference(vec) << endl;
    return 0; 
}