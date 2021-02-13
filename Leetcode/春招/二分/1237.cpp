#include <bits/stdc++.h>
using namespace std;

class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y){
        return x * y;
    }
};

/* class Solution { // 写暴毙了
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        int lhs = 1;
        int rhs = 1000;
        int ans = rhs + 1;
        vector<vector<int>> result;
        vector<int> path;
        while(lhs < rhs){
            int l = lhs;
            int r = (ans == rhs + 1 ? rhs : ans); // 可能在某一次遍历中不存在答案
            cout << l << " " << r << endl;
            ans = r + 1;
            int temp = ans;
            while(l <= r){
                int mid = l + (r - l)/2;
                if(customfunction.f(lhs, mid) <= z || customfunction.f(mid, lhs) <= z){
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if(ans != temp && (customfunction.f(lhs, ans) == z || customfunction.f(ans, lhs) == z)){    // 这种方法写二分如果不存在，值定位到期待值的上一个
                if(customfunction.f(lhs, ans) == z)result.push_back({lhs, ans});
                if(lhs != ans && customfunction.f(ans, lhs) == z) result.push_back({ans, lhs});
                rhs = ans - 1;
            }
            cout << lhs << " : " << ans << endl;
            lhs++;
            cout << ans << endl;
        }
        return result;
    }
};  //a,b不对b,a可能对 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        int left = 1, right = 1000;//右边界right会不断缩小
        for(int x = 1; x <= 1000; x++) {
            left = 1;//每次左边界left从1开始；好巧妙，比我那个好多了
            while(left <= right) {
                int middle = (left + right) / 2;
                int temp = customfunction.f(x, middle);
                if(temp == z) {
                    res.push_back({x, middle});
                    right = middle - 1;//缩小右边界
                    break;
                }
                else if(temp < z) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;//缩小右边界
                }
            }
            //其实发现 right == 0 了可以直接返回
        }
        return res;
    }
};

int main(){
    Solution sol;
    CustomFunction f;
    auto res = sol.findSolution(f, 5);
    cout << "result : \n";
    for(auto item : res){
        for(auto x : item){
            cout << x << " ";
        }
        putchar('\n');
    }

    return 0;
}