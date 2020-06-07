// 单词接龙 II
#include <bits/stdc++.h>
using namespace std;

/* class Solution {
public: //题理解错了,不想写了,直接copy吧
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mp;
        unordered_map<int, string> mps;         
        int index = 0;
        // 建立数字和string的映射，提高效率
        //wordList.push_back(beginWord);
        //wordList.push_back(endWord);
        int flag1 = 0, flag2 = 0;
        for(auto x : wordList){
            if(x == beginWord){
                flag1++;
            }else if(x == endWord){
                flag2++;
            }
        }
        if(!flag1) wordList.push_back(beginWord);
        if(!flag2) wordList.push_back(endWord);
        for(const auto& item : wordList){
            mp[item] = index;
            mps[index++] = item;
        }

        vector<vector<int>> graph(wordList.size());
        // 建图
        for(size_t i = 0; i < wordList.size(); i++){
            for(size_t j = 0; j < wordList.size(); j++){   
                if(i != j && transformCheck(wordList[i], wordList[j])){
                    graph[mp[wordList[i]]].push_back(mp[wordList[j]]);
                }
            }
        }

        // Cost用于排除已经访问过的节点，很巧妙,Cost[i]为这个点到起点的长度，单位为1
        vector<int> Cost(wordList.size(), 0x3f3f3f3f); // index起始点为0
        Cost[mp[beginWord]] = 0;

        vector<vector<string>> res; // 存储路径
        int result_size = 0x3f3f3f3f;
        queue<vector<int>> que;
        que.push({mp[beginWord]});
        while(que.size()){
            vector<int> Temp = std::move(que.front());

            for(auto x : Temp){
                cout << x << " ";
            } 
            putchar('\n');

            if(Temp.size() > result_size) break; // 因为是bfs，当答案长度大于第一次更新的result_size的时候退出循环 其实有一点小小的问题
            que.pop();
            int node = Temp.back(); //队列中的最后一个值为下一步要插入的起始点
            if(node == mp[endWord] && Temp.size() <= result_size){ //找到答案 答案后面的点不用更新了
                vector<string> T;
                for(auto x : Temp){ //把int转化成string
                    T.push_back(mps[x]);
                }
                res.emplace_back(std::move(T));
                result_size = Temp.size();
                continue;
            }
            for(auto x : graph[node]){ //得到与node相邻接的点
                if(Cost[x] >= Cost[node]+1){ //这个节点还没有被遍历或只相差1
                    Cost[x] = Cost[node]+1;
                    vector<int> T = Temp;
                    T.push_back(x);
                    que.push(std::move(T));
                }
            }
        }
        return res;
    }
private:
    bool transformCheck(const string& str1, const string& str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                ++differences;
            }
        }
        return differences == 1;
    }
};
 */

const int INF = 1 << 20;

class Solution {
private:
    unordered_map<string, int> wordId;
    vector<string> idWord;
    vector<vector<int>> edges;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int id = 0;
        for (const string& word : wordList) {
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(endWord)) {
            return {};
        }
        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }
        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); i++) {
            for (int j = i + 1; j < idWord.size(); j++) {
                if (transformCheck(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        const int dest = wordId[endWord];
        vector<vector<string>> res;
        queue<vector<int>> q;
        vector<int> cost(id, INF);
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;
        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();
            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int index : now) {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); i++) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }

    bool transformCheck(const string& str1, const string& str2) {
        int differences = 0;
        for (int i = 0; i < str1.size() && differences < 2; i++) {
            if (str1[i] != str2[i]) {
                ++differences;
            }
        }
        return differences == 1;
    }
};

int main(){
    Solution sol;
    vector<string> Words = {"hot","dot","dog","lot","log"};
    auto x = sol.findLadders("hit", "cog", Words);
    for(auto xx : x){
        for(auto yy : xx){
            cout << yy << " ";
        }
        putchar('\n');
    }
    return 0;
}