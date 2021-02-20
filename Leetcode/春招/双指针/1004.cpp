#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int lhs = 0;
        int target = 0;
        int res = 0;
        for (size_t i = 0; i < A.size(); i++){
            if(A[i] == 1){
                res = max<int>(i - lhs + 1, res);
            } else {
                target++;
            }
            if(target <= K) res = max<int>(i - lhs + 1, res);
            while(target > K){
                if(A[lhs] == 0){
                    target--;
                }
                lhs++;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    std::cout << sol.longestOnes(vec, 3) << endl;
    return 0;
    }