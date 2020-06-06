//  困于环中的机器人
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 把这一系列参数看做一个指令，即（跳转+改变方向）
    bool isRobotBounded(string instructions) {
            if (!(instructions.size() >= 1 && instructions.size() <= 100)) return false;
            int d = 0;  //四个方向 0上1右2下3左  这样定是为了满足 d+1就是向左转 d+3就是向右转
            int dx[] = {0, 1, 0, -1};//索引和方向对应
            int dy[] = {1, 0, -1, 0};
            int x = 0;
            int y = 0;
            for (auto eachIns:instructions) {
                switch (eachIns) {
                    case 'R':
                        d += 1;
                        break;
                    case 'L':
                        d += 3; //不用d-=1 是因为当d变成负数的时候，取mod会出错
                        break;
                    case 'G':
                        d = d % 4;
                        x = x + dx[d];
                        y = y + dy[d];
                        break;
                }
            }
            // 不为原点且方向为上的话不会形成环
            return ((x == 0 && y == 0) || d % 4 != 0);
    }
};