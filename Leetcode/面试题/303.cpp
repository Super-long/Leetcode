#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1, 0);
        for(int i = 1; i < nums.size() + 1; ++i){
            prefix[i] = nums[i - 1] + prefix[i-1];
            cout << prefix[i] << endl;
        }
    }
    
    int sumRange(int i, int j) {
        return prefix[j+1] - prefix[i]; 
    }
};

int main(){
    vector<int> vec = {-2, 0, 3, -5, 2, -1};
    NumArray num(vec);
    cout << num.sumRange(0, 2) << endl;
    cout << num.sumRange(2, 5) << endl;
    cout << num.sumRange(0, 5) << endl;
}