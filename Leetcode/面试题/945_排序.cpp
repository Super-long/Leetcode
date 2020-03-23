//使数组唯一的最小增量

#include <bits/stdc++.h>
using namespace std;

class Solution { //nlogn
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(), A.end());
        int Move = 0;
        for(int i=1;i<A.size();++i){
            if(A[i]<=A[i-1]){
                int temp = A[i-1]-A[i];
                if(temp >= 0){
                    Move += temp+1;
                    A[i] = A[i-1]+1;
                }
            }
        }
        return Move;
    }
};



int main(){
    vector<int> vec = {1,2,3,3,7,8,9};
    Solution sol;
    cout << sol.minIncrementForUnique(vec) << endl;
    return 0;
}