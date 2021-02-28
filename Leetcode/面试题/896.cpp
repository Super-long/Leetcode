#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool flag = false;
        int len = A.size() - 1;
        if(A[0] > A[len]){
            flag = true;
        } else if(A[0] < A[len]){
            flag = false;
        } else {
            for(auto x : A){
                if(x != A[0]){
                    return false;
                }
            }
            return true;
        }
        for(int i = 0; i < len; ++i){
            if(flag && A[i] < A[i + 1]){
                return false;
            }
            if(!flag && A[i] > A[i + 1]){
                return false;
            }
        }
        return true;
    }
};