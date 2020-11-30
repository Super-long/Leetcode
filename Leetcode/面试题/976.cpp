#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if(A.size() < 3) return 0;
        sort(A.begin(), A.end(), greater<int>());
        int base = 0;
        int lhs = 1;
        int rhs = 2;
        for (size_t i = 0; i < A.size() - 2; i++){
            //cout << A[base ] << " " << A[lhs] << " " << A[rhs] << endl;
            if(A[lhs]+ A[rhs]> A[base]){
                return A[base]+A[lhs]+A[rhs];
            } else {
                base++;
                lhs++;
                rhs++;
            }
        }
        return 0;
    }
};

int main(){
    vector<int> vec = {3,9,2,5,2,19};
    Solution sol;
    cout << sol.largestPerimeter(vec) << endl;
    return 0;
}