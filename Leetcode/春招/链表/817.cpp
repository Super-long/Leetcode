#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 哈希或者bitset都可以
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> vis;
        for(auto item : G) vis.insert(item);
        int count = 0;
        bool flag = false;
        while(head){
            if(!flag && vis.find(head->val) != vis.end()){
                flag = true;
                count++;
            } else if(flag && vis.find(head->val) == vis.end()){
                flag = false;
            }
            head = head->next;
        }
        return count;
    }
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
       bitset<10000>  mask;
        bool is_new_component = true;
        int component_num = 0;
        for(int i = 0; i < G.size(); i++)
            mask.set(G[i]);
        while(head)
        {
            if(mask.test(head->val))
            {
                if(is_new_component)
                {
                    component_num++;
                    is_new_component=false;
                }
                mask.reset(head->val);
            }
            else 
                is_new_component=true;
            head = head->next;
        }
        return component_num;
    }
};