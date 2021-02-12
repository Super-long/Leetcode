#include <bits/stdc++.h>
using namespace std;

#define col (5)

struct node{
    int x1, y1;
    int x2, y2;
};

class Redbag{
    private:
        vector<unordered_map<int, bool>> graph;   // bool代表是否被遍历
        vector<int> path;
        vector<int> res;
        int result_num = 0;
        int count;
        int target;
        bool flag = false;
        void dfs(int point){
            if(count == target && !flag){
                result_num++;
                res = path;
                flag = true;
                return;
            }
            for(auto& x : graph[point]){
                if(!x.second) continue;

                path.push_back(x.first);
                count++;
                x.second = false;
                graph[x.first][point] = false;

                dfs(x.first);

                count--;
                graph[x.first][point]= true;
                x.second = true;
                path.pop_back();
            }
        }
    public:
        vector<vector<int>> find(const vector<node>& edges){
            graph.resize(col*col);
            target = edges.size();

            auto conversion = [&](int lhs, int rhs){
                return lhs * col + rhs;
            };
            for(auto& item : edges){
                graph[conversion(item.x1, item.y1)].insert(make_pair(conversion(item.x2, item.y2), true));
                graph[conversion(item.x2, item.y2)].insert(make_pair(conversion(item.x1, item.y1), true));
            }
            for(auto x : graph){
                cout << x.size() << endl;   // 图建错了，不止两个奇数结点;这个图建的不满足欧拉图定义，
            }
            
            for (int i = 0; i < col*col; i++){
                if(flag) break;
                count = 0;
                path.clear();
                path.push_back(i);
                dfs(i);
                cout << result_num << endl;
            }
            
            auto Exchange = [](int node) -> pair<int, int> {
                return {node/col, node%col};
            };
            
            vector<vector<int>> temp; 
            for(auto x : res){
                int one = x/col;
                int two = x%col;
                cout << x << " " << one << " " << two << endl;
                //temp.push_back({one, two});
            }

            return temp;
        }
};

/*
        {0,0,1,1},  col == 3
        {0,0,1,0},
        {0,2,1,1},
        {0,2,1,2},
        {1,0,2,0},
        {1,1,2,0},
        {1,1,2,2},  
        {1,2,2,2},
        {2,0,2,1},
        {2,1,2,2}
*/

int main(){
    vector<node> vec = {
        {0,0,2,2},  // col == 5
        {0,0,1,2},
        {0,1,1,0},
        {0,1,1,1},
        {0,2,1,2},
        {0,2,2,3},
        {0,3,2,2},
        {0,3,1,3},
        {0,4,1,2},
        {0,4,1,3},  // 第一行
        {1,0,2,0},
        {1,0,2,1},
        {1,0,2,2},
        {1,1,2,1},
        {1,2,2,1},
        {1,2,3,1},
        {1,2,2,3},
        {1,3,2,2},
        {1,3,2,3},
        {1,3,1,4},
        {1,4,2,2},  // 第二行
        {2,0,3,0},
        {2,0,2,1},
        {2,0,3,2},
        {2,1,2,2},
        {2,1,4,2},
        {2,1,4,3},
        {2,2,3,3},
        {2,2,2,3},
        {2,3,2,4},
        {2,3,3,4},
        {2,4,3,4},  //第三行
        {3,0,4,2},
        {3,1,3,2},
        {3,2,3,3},
        {3,2,4,1},
        {3,3,4,3},
        {3,3,4,4},
        {4,0,4,1},
        {4,3,4,4}
    };
    Redbag rb;
    auto res = rb.find(vec);
    cout << "hello\n";
    for(auto item : res){
        cout << item[0] << " " << item[1] << endl;
    }
    return 0;
}