#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
                int j = 1; // 代表奇数
                for (int i = 0; i < A.size(); i+=2){
                    if(A[i]%2 == 1){
                        while (A[j]%2==1){
                            j+=2;   // 得到偶数退出
                        }
                        swap(A[j], A[i]);
                        j+=2;
                    }
                }
                return A;
    }
};