// 有序矩阵中第K小的元素
#include <bits/stdc++.h>
using namespace std;

/* class Solution { // 归并排序
private:
    struct node{
        int val;
        int x;
        int y;
        node(int v, int xx, int yy) :
            val(v), x(xx), y(yy){}
        bool operator>(const node& para) const{
            return this->val > para.val;
        }
    };
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<node, vector<node>, greater<node>> que;
        for(size_t i = 0; i < matrix.size(); i++){
            que.emplace(matrix[i][0], i, 0);
        }
        int index = 1;
        while(que.size() && index != k){
            auto point = que.top();
            cout << point.val << " " << point.x << " " << point.y << endl;
            que.pop();
            index++;
            if(point.y + 1 < matrix.size())
                que.emplace(matrix[point.x][point.y+1], point.x, point.y + 1);
        }
        return que.top().val;
    }
}; */

class Solution { // 二分
private:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n){
        int sum = 0;    // 小于等于mid的数
        int i = n - 1;
        int j = 0;
        while(j < n && i >= 0){
            if(matrix[i][j] <= mid){
                sum += i +1;
                j++;
            } else {
                i--;
            }
        }
        return sum >= k;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {   
        int l = matrix[0][0];
        int r = matrix[matrix.size() - 1][matrix.size() - 1];
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(matrix, mid, k, matrix.size())){   // 小于等于mid的数字数小于k
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> vec = {
        {1,5,9},
        {10,11,13},
        {12,13,15}
/*         {1,2},
        {1,3} */
    };
    cout << sol.kthSmallest(vec, 8) << endl;
    return 0;
}