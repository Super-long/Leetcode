#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* class Solution {
private:
    TreeNode* res = nullptr;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false;
        bool lhs = dfs(root->left, p, q);
        bool rhs = dfs(root->right, p, q);
        cout << lhs << " " << rhs << endl;
        if((lhs && rhs) || ((root->val == p->val || root->val == q->val) && (rhs || lhs))){ // 不知道已经匹配的是哪一个结点
            res = root;
        }
        return lhs || rhs || root->val == p->val || root->val == q->val;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }
};
 */

class Solution {    // 此种写法建立在树上结点的值不相同
private:
    unordered_map<int, TreeNode*> vis;   //记录每个结点的父节点 
    unordered_set<int> se;

    void dfs(TreeNode* root, TreeNode* father){
        if(!root) return;
        if(father) vis[root->val] = father;
        se.insert(root->val);
        dfs(root->left, root);
        dfs(root->right, root);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, nullptr);
        while(vis.find(p->val) != vis.end()){
            int temp = p->val;
            p = vis[temp];
            se.erase(temp); // root结点没办法删
        }

        while(vis.find(q->val) != vis.end()){
            int temp = q->val;
            if(se.find(temp) == se.end()){
                return q;
            }
            q = vis[temp];
        }
        return root;
    }
};

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/bao-li-and-bei-zeng-dp-by-old8/
class Solution {    // LCA倍增法
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    const int maxf = 22;
    map<TreeNode*, int> vis;
    map<TreeNode*, TreeNode*> pre[maxf];    // f(u, k)表示u节点的第2^k个祖先
    function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* fa, TreeNode* rt, int dep) {
      vis[rt] = dep;
      pre[0][rt] = fa;
      for (int i = 0; (1 << i) <= vis[fa] && i < maxf; i++) {
        pre[i + 1][rt] = pre[i][pre[i][rt]];
      }
      if (rt->left) dfs(rt, rt->left, dep + 1);
      if (rt->right) dfs(rt, rt->right, dep + 1);
    };
    dfs(NULL, root, 1);
    if (vis[p] < vis[q]) swap(p, q);
    for (int i = maxf - 1; i >= 0; i--) {
      if (vis[p] >= (1 << i) && vis[pre[i][p]] >= vis[q]) p = pre[i][p];
      if (p == q) return p;
    }

    // 查找的实际是公共祖先的孩子。这样可以防止找到深度小于最近公共祖先的结点时无法分辨
    for (int i = maxf - 1; i >= 0; i--) {
      if (vis[p] >= (1 << i) && pre[i][p] != pre[i][q]) {
        p = pre[i][p];
        q = pre[i][q];
      }
    }
    return pre[0][p];
  }
};
