#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {    // 递归
public:
    Node* connect(Node* root) {
        if(root != nullptr){
            dfs(root);
        }
        return root;
    }

    void dfs(Node* root) {
        if(root->left == nullptr){
            return;
        }        
        root->left->next = root->right;
        if(root->next != nullptr){
            root->right->next = root->next->left;
        } 
        connect(root->left);
        connect(root->right);
    }
};

