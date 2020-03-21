#include <bits/stdc++.h>
using namespace std;

//水壶问题

class Solution {
private:
using PII = pair<int, int>;
function<unsigned long(const PII&)> hash_function = 
        [](const PII& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
unordered_set<PII, decltype(hash_function)> se;
int xx,yy,res;
int flag;
public:
    Solution() : se(0,hash_function){}
    bool canMeasureWater(int x, int y, int z) {
        xx = x;
        yy = y;
        res = z;
        flag = 0;
        int remain_x = 0, remain_y = 0;
        se.clear();
        dfs(0,0);
        return flag;
    }

    void dfs(int x, int y){
        if(flag) return;
        if(se.find({x,y}) == se.end()){
            se.insert(std::make_pair(x, y));
            if(x == res || y == res || x + y == res){
                flag = 1;
                return;
            }
            dfs(xx, y); //x倒满
            dfs(x, yy); //y倒满
            dfs(0, y);  //x倒空
            dfs(x, 0);  //y倒空
            dfs(x-min(x, yy-y), y + min(x, yy-y)); //x水倒入y
            dfs(x+min(y,xx-x), y-min(y,xx-x)); //y水倒入x
        } //所有状态搜过以后跳出递归
    }
};

int main(){
    Solution sol;
    int x,y,z;
    cin >> x >> y >> z;
    cout << sol.canMeasureWater(x, y, z) << endl;
    cin >> x >> y >> z;
    cout << sol.canMeasureWater(x, y, z) << endl;
}

//样例 22003 31237 123