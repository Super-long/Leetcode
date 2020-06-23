// 最佳观光组合
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if(!A.size()) return 0;
        int Max = 0;
        int res = 0;
        int index = 0;
        for(int i = 0; i < A.size(); i++){
            //cout << index << " " << i << endl;
            if(index != i)
                res = max(res, Max + A[i] - i);

            if(Max < A[i]+i){
                Max = A[i]+i;
                index = i;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {8,1,5,2,6};
    cout << sol.maxScoreSightseeingPair(vec) << endl;
    return 0;
}