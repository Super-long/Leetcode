#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int res = 0;
        for(int i = 0; i < customers.size(); ++i){
            if(!grumpy[i]) res += customers[i];
        }
        int lhs = 0;
        int item = res;
        for (int i = 0; i < grumpy.size(); ++i){
            if(grumpy[i]) res += customers[i];
            while(i - lhs + 1 > X){
                if(grumpy[lhs]){
                    res -= customers[lhs];
                }
                lhs++;
            }
            item = max<int>(res, item);
        }
        return item;
    }
};


int main(){
    Solution sol;
    vector<int> vec1 = {1,0,1,2,1,1,7,5};
    vector<int> vec2 = {0,1,0,1,0,1,0,1};
    std::cout << sol.maxSatisfied(vec1, vec2 ,3) << endl;
    return 0;
}