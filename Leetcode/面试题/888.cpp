#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mpA, mpB;
        int lenA = A.size();
        int lenB = B.size();
        int numsA = 0;
        int numsB = 0;
        for(auto x : A){
            mpA[x]++;
            numsA += x;
        }
        for(auto x : B){
            mpB[x]++;
            numsB += x;
        }
        int target = (numsA + numsB) / 2;
        for(auto x : A) {
            if(mpB.find(target - (numsA - x)) != mpB.end() && numsA - x == x){
                return {x, target - (numsA - x)};
            }
        }
        return {};
    }
};

/* class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int delta = (sumA - sumB) / 2;
        unordered_set<int> rec(A.begin(), A.end());
        vector<int> ans;
        for (auto& y : B) {
            int x = y + delta;
            if (rec.count(x)) {
                ans = vector<int>{x, y};
                break;
            }
        }
        return ans;
    }
};
 */
int main(){
        Solution sol;
    vector<int> vecA = {1,2};
    vector<int> vecB = {2,3};
    auto res = sol.fairCandySwap(vecA, vecB); 
    for(auto x : res) cout << x << endl;
}