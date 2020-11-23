#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[1] < v[1];
        });
        
        int rhs = 0;
        int res = 0;
        int index = 0;
        while(index < points.size()) {
            rhs = points[index++][1];
            ++res;
            while(index < points.size() && rhs >= points[index][0]){
                index++;
            }
        }

        return res;
    }
};