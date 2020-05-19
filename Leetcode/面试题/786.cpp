//第 K 个最小的素数分数
#include <bits/stdc++.h>
using namespace std;

class Solution { // 这题算是相当难了
private:
    int check(const vector<int>& A, double val){
        int sum = 0;
        for(size_t i = 0; i < A.size(); i++){
            sum += A.end() - upper_bound(A.begin()+i+1, A.end(), A[i]/val);
        }
        return sum;
    }

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double lhs = 0.0;
        double rhs = 1.0;
        while(lhs < rhs){
            double mid = (lhs + rhs) / 2;
            int count = check(A, mid);
            if(count == K){
                lhs = rhs = mid;
                break;
            }else if(count < K){
                lhs = mid;
            }else {
                rhs = mid;
            }
        }
        double target = lhs; //返回的值始终大于等于第K个值 我们要求p/q的值小于target且最接近于target

        int p = 1;
        int q = A.back();

        for(int i = 0; i < A.size(); i++){  
            int tp = A[i];
            auto item = upper_bound(A.begin() + i + 1, A.end(), A[i] / target);
            if(item != A.end()){
                int tq = *item;
                double td = 1.0*tp / tq;
                if(td < target && target - td < target-1.0*p/q){ // 
                    p = tp;
                    q = tq;
                }
            }
        }
        return {p, q};
    }
};

int main(){
    Solution sol;
    vector<int> vec = {1, 2, 3, 5};
    auto res = sol.kthSmallestPrimeFraction(vec, 3);
    for(auto x : res){
        cout << x << endl;
    }
    return 0;
}