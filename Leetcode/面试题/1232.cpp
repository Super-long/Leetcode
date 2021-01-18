#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 1) return false;
        if(coordinates.size() == 2) return true;

        if(coordinates[1][0] - coordinates[0][0] == 0){
            for (size_t i = 0; i < coordinates.size(); i++) {
                if(coordinates[i][0] != coordinates[0][0]) return false;
            }
            return true;
        }

        double k = (coordinates[1][1] - coordinates[0][1])/double((coordinates[1][0] - coordinates[0][0]));
        cout << k << endl;
        for(int i = 2; i < coordinates.size(); i++) {
            cout << abs((coordinates[i][1] - coordinates[0][1]) - k*(coordinates[i][0] - coordinates[0][0])) << endl;
            if(abs((coordinates[i][1] - coordinates[0][1]) - k*(coordinates[i][0] - coordinates[0][0])) >= 0.00001){
                return false;
            }
        }
        return true;
    }
};