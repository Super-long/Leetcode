// 最大连续1的个数 III
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*     int longestOnes(vector<int>& A, int K) {
        if(!A.size()) return 0;
        int MaxSum = 0;
        int lhs=0, rhs=0;
        if(A[0] == 0) --K;
        while(rhs < A.size()){
            if(A[rhs] == 0){
                //cout<< "K : " << K << endl;
                if(K > 0){
                    ++rhs;
                    --K;
                } else {
                    if(A[lhs] == 0){
                        ++lhs;
                        ++K;
                    }else {
                        ++lhs;
                    }
                }
            } else {
                ++rhs;
            }
            MaxSum = max(MaxSum, rhs - lhs + 1);
            cout << lhs << " " << rhs << " " << K << " " <<MaxSum << endl;
        }
        return MaxSum;
    } */

    int longestOnes(vector<int>& A, int K){ // 看问题的角度很刁钻
        int lhs=0,rhs=0,count=0,result=0,size=A.size();
        while(rhs < size){
            count += A[rhs] == 0;
            while(count > K){ //窗口内0大于K 缩小窗口
                count -= A[lhs] == 0;
                ++lhs;
            }
            result = max(result, rhs - lhs + 1);
            ++rhs;
        }
        return result;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1,1,1,0,0,0,1,1,1,1,0};
    cout << sol.longestOnes(vec, 2) << endl;
    return 0;
}