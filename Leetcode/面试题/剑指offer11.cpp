// 旋转数组的最小数字
#include <bits/stdc++.h>
using namespace std;

class Solution {
// return *min_element(numbers.begin(), numbers.end());
public:
    int minArray(vector<int>& numbers) {
        int lhs = 0;
        int rhs = numbers.size() - 1;
        while(lhs < rhs){
            int mid = (lhs + rhs) / 2;
            if(numbers[mid] < numbers[rhs]){ // mid是最小值有责或者就是最小值 忽略右侧
                rhs = mid;
            }else if(numbers[mid] > numbers[rhs]){  // 最小值一定在右侧
                lhs = mid + 1;
            }else { // 精彩的一步 即在无法确定的时候选择忽略右端点 逼近到上两种情况
                rhs--;
            }
        }
        return numbers[lhs];
    }
};