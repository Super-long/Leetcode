#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res(encoded.size() + 1, 0);
        res[0] = first;
        for (size_t i = 0; i < encoded.size(); i++){
            res[i + 1] = res[i] ^ encoded[i];
        }
        for(auto x : res) cout << x << " ";
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {6,2,7,3};
    auto res = sol.decode(vec,4);
    return 0;
}