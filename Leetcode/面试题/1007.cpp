// 行相等的最少多米诺旋转
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 写错了 丢
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        if(!A.size()) return 0;
        int baseA = 0;
        int baseB = 0;
        bool flagA = false;
        bool flagB = false;
        for(size_t i = 1; i < A.size(); i++){
            if(A[i] != A[0]){
                if(B[i] == A[0]){
                    baseA++;
                } else { 
                    flagA = true;
                }
            }
        }
        for(size_t i = 0; i < B.size(); i++){
            if(B[i] != B[0]){
                if(A[i] == B[0]){
                    baseB++;
                } else {
                    flagB = true;
                }
            }
        }
        if(flagA) baseA = -1;
        if(flagB) baseB = -1;
        return min(baseA, baseB);
    }
}; */

class Solution {
    public:
    int check(int x, vector<int>& A, vector<int>& B, int n) {
        int rotations_a = 0, rotations_b = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != x && B[i] != x) return -1;
            else if (A[i] != x) rotations_a++;
            else if (B[i] != x) rotations_b++;
        }
        return min(rotations_a, rotations_b);
    }

    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int rotations = check(A[0], B, A, n);
        if (rotations != -1 || A[0] == B[0]) return rotations;
        else return check(B[0], B, A, n);
    }
};