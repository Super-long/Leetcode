// 时钟指针的夹角
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int ho, int mi) {
        double hour = ho;
        double minutes = mi;
        double h = ((hour + (minutes/60)) * 30);
        if(h >= 360) h-=360;
        double m = ((minutes ) * 6);
        if(m >= 360) m-=360;
        cout << h << " " << m << endl;
        double diff = abs(h - m);
        double Min = (diff);
        double Max = (360 - diff);
        return min(Min, Max);
    }
};

int main(){
    Solution sol;
    cout << sol.angleClock(12, 30) << endl;
    return 0;
}