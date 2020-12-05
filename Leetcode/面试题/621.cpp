#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_map<char, int> countMap;
public:
    int leastInterval(vector<char>& tasks, int n) { // 最大的问题在于没办法找到前N大，遍历的话复杂度太高，其实每次就是遍历26次；
        for(auto x : tasks) {
            countMap[x]++;
        }

        int res = 0;
        while(countMap.size()){
            int loop = n + 1;
            vector<int> temp;
            for(auto& x : countMap) {
                if(loop){
                    cout << x.first << endl;
                    x.second--;
                    if(x.second == 0) temp.push_back(x.first);
                    res++;
                    loop--;
                } else {
                    break;
                }
            }
            for(auto x : temp) {countMap.erase(x);}
            if(loop > 0 && countMap.size()){
                cout << n + 1 - loop << " " << loop << endl;
                res += loop;
            }
        }

        return res;
    }
};

int main(){ // 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'
    vector<char> vec = {'A','A','A','B','B','B', 'C','C','C', 'D', 'D', 'E'};   // 这种题每轮循环都要找最大的那个；
    Solution sol;
    cout << sol.leastInterval(vec, 2) << endl;
    return 0;
}

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) { // 妈的，这样写真的蠢，但是确实是对的
        int wait[26] = { 0 };
        int catogory[26] = { 0 };
        for(int i = 0;i<tasks.size();i++)
        {
            catogory[tasks[i]-'A']++;
        }
        //把任务个数统计到catogory里面
        int ans = 0;
        int loss = 0;
        int nn = tasks.size();
        //loss表示已经完成的任务数 nn表示总共的任务数
        while(loss < nn)
        {
            int max = -1;
            //在空闲的任务中贪心的找还剩余最多的那个任务，必须把它放在前面，因为后面要冷却
            for(int i=0;i<26;i++)
            {
                if(catogory[i]&&!wait[i])
                {
                    if(max == -1||catogory[max]<catogory[i])
                    max = i;
                }
            }
            if(max != -1)//没有更新说明所有任务都在冷却
            {
                loss++;
                catogory[max]--;
                //该种任务做了一件，冷却时间+n+1（因为之后的时间加1是对于所有的都减1，加n会使得间距只有n-1）
                wait[max] = n+1;
            }
            //时间+1，所有冷却中的任务wait时间--
            for(int j=0;j<26;j++)
            {
                if(wait[j])
                wait[j]--;
            }
            //ans记录时间+1
            ans++;
        }
        return ans;
    }
};