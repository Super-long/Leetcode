// 二叉树的序列化与反序列化
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()){
            auto T = que.front();
            que.pop();
            if(T != nullptr){
                res += to_string(T->val) + ",";
            }else {
                res += "n,";
                continue; //没办法搞了，写崩了
            }
            que.push(T->left);
            que.push(T->right);
        }
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root;
        int lhs = 0, rhs = 0;
        short flag = 0;
        queue<TreeNode*> que;
        while(rhs < data.size()){
            while(data[rhs] != ','){
                ++rhs;
            }
            string S = data.substr(lhs , rhs - lhs);
            cout << S << endl;
            TreeNode* node = nullptr;
            if(S[0] != 'n')
                node = new TreeNode(stoi(S));
            ++rhs;
            lhs = rhs;
            // 以上是为了把data中的每一项数据搞出来，下面是建树
            if(que.size()){
                TreeNode* T = que.front();
                if(flag == 0 && T){
                    T->left = node;
                    flag = 1;
                } else if(T) {
                    T->right = node;
                    que.pop();
                    flag = 0;
                }
            } else {
                root = node;    // 记录答案
            }
            que.push(node);
        }
        return root;
    }
};

int main(){
    Codec sol;
    string str = "1,2,3,n,n,4,5,n,n,n,n,";
    auto x = sol.deserialize(str);
    return 0;
}