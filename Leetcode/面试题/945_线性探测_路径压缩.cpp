#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        vector<int> vis;
        vis.resize(80000+10, -1); //有可能所有的数字都是40000 所以我们的值得大于二倍
        int Move = 0;
        for(int i = 0; i < A.size(); i++){
            if(vis[A[i]]!=-1){
                Move += (findpos(A[i], vis)-A[i]);
            }else{
                vis[A[i]] = A[i];
            }
        }
        return Move;
    }

    int findpos(int a, vector<int>& pos){
        int index = a;
        if(pos[a] == -1){
            pos[a] = a;
            return a;
        }else if(pos[a] == a){
            ++index;
        }else{
            index = pos[a]+1;
        }
        int temp = findpos(index, pos); //返回获取的可以插入的下标
        pos[a] = temp; //路径压缩
        return temp;
    }
};

int main(){
    vector<int> vec = {1,1,2};//
    Solution sol;
    cout << sol.minIncrementForUnique(vec) << endl;
    return 0;
}