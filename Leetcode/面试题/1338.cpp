// 数组大小减半
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num: arr) {
            ++freq[num];
        }
        vector<int> occ;
        for (auto& [k, v]: freq) {
            occ.push_back(v);
        }
        sort(occ.begin(), occ.end(), greater<int>());
        int cnt = 0, ans = 0;
        for (int c: occ) {
            cnt += c;
            ans += 1;
            if (cnt * 2 >= arr.size()) {
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {3,3,3,3,5,5,5,2,2,7};
    cout << sol.minSetSize(vec) << endl;
    return 0;
}