// 拥有最多糖果的孩子

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int MAX = *max_element(candies.begin(), candies.end());
        vector<bool> ret;
        for (int i = 0; i < candies.size(); ++i) {
            ret.push_back(candies[i] + extraCandies >= MAX);
        }
        return ret;
    }
};