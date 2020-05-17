// H 指数
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int res = citations.size();
        sort(citations.begin(), citations.end());
        for(auto x : citations){
            if(x < res) --res;
            else break;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {3,0,6,1,5};
    cout << sol.hIndex(vec) << endl;
    return 0;
}