#include <bits/stdc++.h>
using namespace std;

// https://www.lintcode.com/problem/the-kth-subarray/description?spm=a2c6h.12873639.0.0.3e7027d0Zu04vE&utm_source=sc-tc-sz0810)
// 这个题目不是leetcode的。是lintcode的1139题

/* class Solution {  // 好题，自己写暴毙了
private:
    array<long long, 10000> prev;
    // O(N)的找到nums中有几个小于target的值
    long long equalOrSmaller(vector<int> &nums, long long target){
        int rhs = 0;
        int lhs = 0;

        int res = 0;

        while(rhs < nums.size() && prev[rhs] <= target){    // 跳出循环的时候rhs之前的前缀和大于target
            rhs++;
        }
        res = rhs;  // 至少rhs个子数组小于等于target

        for (size_t i = 0; i < nums.size(); i++){
            rhs = max<size_t>(rhs, i + 1);// 显然i == 0 不能重新计算了
            while(rhs < nums.size() && prev[rhs] - prev[i] <= target){
                rhs++;
            }
            res += rhs - i  - 1;
        }

        return res;
    }
public:
    long long thekthSubarray(vector<int> &a, long long k) {
        prev[0] = a[0];
        for (size_t i = 1; i < a.size(); i++){
            prev[i] = prev[i - 1] + a[i];
        }
        long long lhs = 0;
        long long rhs = 1e14;
        while(lhs < rhs){
            int mid = lhs + (rhs - lhs) / 2;
            if(equalOrSmaller(a, mid) < k){
                lhs = mid + 1;
            } else {
                rhs = mid;
            }
        }
        return lhs;
    }
}; */

class Solution {
public:
    /**
     * @param a: an array
     * @param k: the kth
     * @return: return the kth subarray
     */
    long long thekthSubarray(vector<int> &a, long long k) 
    {
        int n = a.size();
        vector<long long>presum(n,0);
        presum[0] = a[0];
        for (int i=1; i<n; i++)
            presum[i] = presum[i-1]+a[i];
            
        long long left = 0;
        long long right = 1e14;
        
        while (left<right)
        {
            long long mid = left+(right-left)/2;
            long long count = equalOrSmaller(mid, presum);
            if (count < k)
                left = mid+1;
            else
                right = mid;
        }
        
        return left;
    }
    
    long long equalOrSmaller(long long target, vector<long long>&presum)
    {
        int i = 0, j = 0;
        long long count = 0;
        while (j<presum.size() && presum[j] <= target)
            j++;
        count = j;
        
        // 前缀和计算的是(i, j]区间的值
        for (int i=0; i<presum.size(); i++)
        {
            while (j<presum.size() && (presum[j]-presum[i])<=target)
                j++;
            count+=(j-i-1);
            cout << count << endl;
        }
        
        return count;
        
    }
};

int main(){
    Solution sol;
    vector<int> vec = {100,3,1,4};
    cout << sol.thekthSubarray(vec, 6) << endl;
    return 0;
}