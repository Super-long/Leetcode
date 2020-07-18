// 大小为 K 且平均值大于等于阈值的子数组数目
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int lhs = 0;
        int rhs = 0;
        int res = 0;
        int num = arr[0];
        while(rhs < arr.size()){
            while(rhs - lhs + 1 < k){
                if(++rhs >= arr.size()) return res;
                num += arr[rhs]; 
            }
            //cout << lhs << " " << rhs << endl;
            if(num / k >= threshold){
                //cout << lhs << " : " << rhs << endl;
                res++;
            }                
            num -= arr[lhs];
            lhs++;
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec = {4,4,4,4};
    cout << sol.numOfSubarrays(vec, 4, 1) << endl;
    return 0;
}