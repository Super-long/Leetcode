#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        int prev = 0;
        for (size_t i = 0; i < time.size(); i++){
            if(i == 0){
                if(time[0] == '?'){
                    time[0] = '2';
                }
            } else if(i == 1){
                if(time[1] >= '4' && time[0] == '2' && time[1] != '?'){
                    time[0] = '1';  // ?4:03
                }
                if(time[1] != '?') continue;
                if(time[0] == '0' || time[0] == '1'){
                    time[1] = '9';
                } else {
                    time[1] = '3';
                }
            } else if(i == 3){
                if(time[3] != '?') continue;
                time[3] = '5';
            } else if(i == 4){
                if(time[4] != '?') continue;
                time[4] = '9';
            }
        }
        return time;
    }
};

int main(){
    Solution sol;
    cout << sol.maximumTime("2?:?0") << endl;
}