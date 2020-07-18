// 所有蚂蚁掉下来前的最后一刻
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(int i = 0; i < left.size(); i++){
            res = max(res, left[i]);
        }
        for(int i = 0; i < right.size(); i++){
            res = max(res, static_cast<int>(right.size() - right[i]));
        }
        return res;
    }
};
//按照第一个例子，当相遇时，BC可以认为不掉头继续走，但是此时AD也会逆向，AD为什么也能算穿透呢？