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
int sum = 0;
    bool ti = false;
    void dfs(TreeNode* n,int t){
        if(n == NULL) return;
        sum+=n->val;
        if(n->left == NULL && n->right == NULL){
              if(sum == t) {ti = true; }
              sum-=n->val;
              return;
        }
        
        dfs(n->left,t);
        dfs(n->right,t);

        sum-=n->val;


    } 

    bool hasPathSum(TreeNode* root, int t) {
        
        dfs(root,t);
        return ti;
    }
};