#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    struct ListNode{
        int num; //每次查询中此点被遍历过多少次 可以在查询答案的时候执行清空
        ListNode* next[26];
        ListNode* root;

        ListNode() : num(0){
        } 
    };

    ListNode* root;
    int L;
    unordered_map<int, ListNode*> mp;
private:
    void BackStack(ListNode* leaves){    
        while(leaves != root){
            leaves->num++;
            leaves = leaves->root;
        }
    }

    int ClearAndCalculation(ListNode* Root){ // dfs
        if(Root == nullptr) return 0;
        int res = 0;
        for(size_t i = 0; i < 26; i++){
            if(Root->next[i] != nullptr){
                if(Root->next[i]->num == L){
                    res++;
                }
                Root->next[i]->num = 0; // 清空
                res += ClearAndCalculation(Root->next[i]);
            }
        }
        return res;
    }

public:
    void Create(const vector<string>& para){
        root = new ListNode();
        root->num = -1;
        for(size_t i = 0; i < para.size(); ++i){
            const string& item = para[i];
            int index = 0;
            ListNode* Temp = root;
            while(index != item.size()){
                if(Temp->next[item[index]-'a'] == nullptr){
                    Temp->next[item[index]-'a'] = new ListNode();
                    Temp->next[item[index]-'a']->root = Temp; //方便回溯
                }
                Temp = Temp->next[item[index]-'a'];
                index++;
            }
            mp[i+1] = Temp; // 哈希表中存放每一个节点的叶子节点
        }
    }

    int Search(const vector<int>& para, int L){
        this->L = L;
        for(size_t i = 0; i < para.size(); i++){
            BackStack(mp[para[i]]);
        }
        return ClearAndCalculation(root);
    }
};

int main(){
    int num, q;
    Solution sol;
    vector<string> para;
    cin >> num >> q;
    for(size_t i = 0; i < num; i++){
        string str;
        cin >> str;
        para.emplace_back(std::move(str));
    }
    sol.Create(para);
    while(q--){
        int K, L;
        cin >> K >> L;
        vector<int> vec;
        for(size_t i = 0; i < K; i++){
            int T = 0;
            cin >> T;
            vec.emplace_back(std::move(T));
        }
        cout << sol.Search(vec, L) << endl;
    }
    return 0;
}