#include <bits/stdc++.h>
using namespace std;

class quickSort{
private:
    void trueSort(vector<int>& nums, int lhs, int rhs){
        if(lhs >= rhs) return;
        int index = rand() % (rhs - lhs + 1) + lhs;

        swap(nums[index], nums[rhs]);
        int res = Partition(nums, lhs, rhs);
        trueSort(nums, lhs, res - 1);
        trueSort(nums, res + 1, rhs);
    }

    int Partition(vector<int>& nums, int lhs, int rhs){
        int target = nums[rhs];
        int index = lhs;
        for (size_t i = lhs; i < rhs; i++){
            if(nums[i] <= target){
                swap(nums[i], nums[index]);
                index++;
            }
        }
        swap(nums[index], nums[rhs]);
        return index;
    }
public:
    void Sort(vector<int>& nums) {
        srand(time(0));
        trueSort(nums, 0, nums.size() - 1);
        return;
    }
};

int main(){
    vector<int> vec = {9,8,7,6,5,4,3,2,1,0};
    quickSort sol;
    sol.Sort(vec);
    for(auto x : vec) cout << x << endl;
    return 0;
}