#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> se;
        for(auto x : nums1) {
            se.insert(x);
        }
        vector<int> result;
        unordered_set<int> set_nums2;
        for(auto x : nums2){
            if(se.count(x) && set_nums2.find(x) == set_nums2.end()){
                set_nums2.insert(x);
                result.push_back(x);
            }
        }
        return result;
    }
};