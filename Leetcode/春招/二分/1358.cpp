#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {  // 这题可以用双指针解
        vector<vector<int>> pre(3, vector<int>(s.size() + 1, 0));
        for (size_t i = 0; i < s.size(); i++){
            pre[s[i] - 'a'][i + 1] ++;  // 一般遇到前缀和要把数组开大，因为[i,j]区间需要j - (i - 1)
            if(i > 0){
                pre[0][i + 1] += pre[0][i];
                pre[1][i + 1] += pre[1][i];
                pre[2][i + 1] += pre[2][i];
            }
        }
        for(auto x : pre){
            for(auto y : x){
                cout << y << " ";
            }
            putchar('\n');
        }
        int res = 0;
        for (size_t i = 0; i < s.size(); i++){
            int lhs = i + 1;
            int rhs = s.size(); // lhs和rhs下标均加1 
            int ans = -1;
            cout << lhs << " - " << rhs << endl;
            while(lhs <= rhs){
                int mid = lhs + (rhs - lhs) / 2;
                cout << mid << endl;
                if(pre[0][mid]-pre[0][i] > 0 && pre[1][mid]-pre[1][i] > 0 && pre[2][mid]-pre[2][i] > 0){    // 是i的原因是加1以后又减1
                    ans = mid;
                    rhs = mid - 1;
                } else {
                    lhs = mid + 1;
                }
            }
            cout <<  i << " " << ans << endl;
            if(ans == -1){
                return res;
            }
            res += s.size() - ans + 1;
        }
        return res;
    }
};

int main(){
    Solution sol;
    std::cout << sol.numberOfSubstrings("aaabc") << endl;
    return 0;
}