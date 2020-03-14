#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> pools;
        for(auto x : nums){
            cout << x << endl;
            pools[x]++;
        }
        for(auto item : pools){
            if(item.second > nums.size()/2)
                return item.first;
        }
    }
};


int main(){
    Solution sol;
    vector<int> vec={3,2,3};
    cout << sol.majorityElement(vec) << endl;
    return 0;
}