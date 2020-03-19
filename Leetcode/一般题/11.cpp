#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int res = 0;
        while(i!=j){ //移动的原则是短板移动面积可能增大 长版移动面积一定减小
            res = max(min(height[i], height[j])*(j-i), res);
            height[i] > height[j] ? --j : ++i;
        }
        return res;
    }
};