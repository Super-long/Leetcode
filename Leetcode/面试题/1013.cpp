#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        cout << sum << endl;
        if(sum%3) return false;
        int Temp = sum/3;
        cout << "Temp : " << Temp << endl;
        int number = 0;
        for(auto item : A){
            Temp -= item;
            if(!Temp){
                Temp = sum/3;
                ++number;
            }
        }
        return number >= 3;
    }
};

int main(){
    Solution sol;
    vector<int> vec={10,-10,10,-10,10,-10,10,-10};
    if(sol.canThreePartsEqualSum(vec)) cout << "true\n";
    else cout << "false\n";
    return 0;
}