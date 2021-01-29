#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int res = INT_MIN;
        int sum = 0;
        for (size_t i = 0; i < rectangles.size(); i++){
            int temp = min(rectangles[i][0], rectangles[i][1]);
            if(temp > res){
                res = temp;
                sum = 1;
            } else if(temp == res){
                sum++;
            }
        }
        return sum;
    }
};