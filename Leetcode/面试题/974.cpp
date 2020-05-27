// 和可被 K 整除的子数组
#include <bits/stdc++.h>
using namespace std;

class Solution { // 数学题 看不懂
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map<int, int> mp = {{0, 1}};
        int pre = 0;
        int sum = 0;
        for(size_t i = 0; i < A.size(); i++){
            pre += A[i];
            int modulus = (pre % K + K) % K;
            sum += mp[modulus];
            mp[modulus]++;
        }
        return sum;
    }
};

int main(){

}