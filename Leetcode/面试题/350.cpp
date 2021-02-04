// 两个数组的交集 II
#include <bits/stdc++.h>
using namespace std;

/* class Solution {    // 内存消耗太大;排序+双指针也可以做
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> n1;
        unordered_map<int, int> n2;
        for(auto x : nums1) n1[x]++;
        for(auto x : nums2) n2[x]++;
        for(const auto& x : n1){
            for(int i = 0; i < min(x.second, n2[x.first]); i++){
                res.push_back(x.first);
            }
        }
        return res;
    }
}; */

class Solution {    // 顺序情况下的优化, 节省空间，且只需要各遍历一遍
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int index1 = 0, index2 = 0;
        int num = max(nums1.size(), nums2.size());
        while(true){
            if(index1 >= nums1.size() || index2 >= nums2.size()){
                break;
            }
            if(nums1[index1] < nums2[index2]){
                index1++;
            }else if(nums1[index1] > nums2[index2]){
                index2++;
            }else {
                res.push_back(nums1[index1]);
                index1++;
                index2++;
            }
        }
        return res;
    }
};

// 还有一种情况,就是nums1的大小比nums2小很多,这个时候小的搞成一个哈希表,把大的遍历一篇,匹配哈希表即可(同时修改)

int main(){
    Solution sol;
    vector<int> nums1 = {1,2,5,8,10};
    vector<int> nums2 = {1,3,5,7,9};
    vector<int> res = sol.intersect(nums1, nums2);
    for(auto x : res){
        cout << x << endl;
    }
    return 0;
}