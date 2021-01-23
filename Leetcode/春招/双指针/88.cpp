#include <bits/stdc++.h>
using namespace std; 

class Solution {
private:
    void iterator_memmove(std::vector<int>::iterator lhs, std::vector<int>::iterator rhs, std::vector<int>::iterator start){
        auto len = std::distance(lhs, rhs);
        auto end = start+len;
        while(start != end){
            *end = *rhs;
            end--;
            rhs--;
        }
        *end = *rhs;
        return;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!nums1.size() || !nums2.size()) return;
        int p1 = 0;
        int p2 = 0;
        int p3 = nums1.size() - m;
        if(m > 0)
        iterator_memmove(nums1.begin(), nums1.begin() + m - 1, nums1.begin()+(nums1.size() - m));
        for(auto x : nums1)
            cout << x << " ";
        putchar('\n');
        cout << p1 << " " << p2 << " " << p3 << endl;

        while(p2 < n && p3 < nums1.size()){
            if(nums1[p3] < nums2[p2]){
                nums1[p1++] = nums1[p3++];
            } else {
                nums1[p1++] = nums2[p2++];
            }
        }

        for(auto x : nums1)
            cout << x << " ";
        putchar('\n');

        cout << p1 << " " << p2 << " " << p3 << endl;

        if(p2 >= n){
            while(p1 < nums1.size()){
                nums1[p1++] = nums1[p3++];
            }
        } else {
            while(p1 < nums1.size()){
                nums1[p1++] = nums2[p2++];
            }
        }

        for(auto x : nums1){
            cout << x << " ";
        }
        putchar('\n');

        return;
        
    }
};

/* 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};
 */

int main(){
    Solution s;
    vector<int> vec1 = {2, 0};
    vector<int> vec2 = {1};
    s.merge(vec1,1, vec2, 1);
    return 0;
}