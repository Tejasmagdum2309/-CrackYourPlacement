/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    // bool f = true;

    bool dfs(TreeNode* p,TreeNode* q){
          if(p == NULL && q == NULL) return true;

          if((p == NULL && q != NULL) || (q == NULL && p != NULL) || (p->val != q->val)){
            // f = /;
            return false;
          }

          return (dfs(p->left,q->left)) && (dfs(q->right,p->right));

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
         return dfs(p,q);
    }
};