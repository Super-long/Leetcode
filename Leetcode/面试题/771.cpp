#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> vis;
        for(auto x : J){
            vis.insert(x);
        }
        int number = 0;
        for(auto x : S){
            if(vis.find(x) != vis.end()){
                ++number;
            }
        }
        return number;
    }
};