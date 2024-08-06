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
    bool ans = true;

    void dfs(TreeNode* l,TreeNode* r){
        if(l == NULL && r == NULL) return;

        if(l == NULL || r == NULL || (l->val != r->val)){ans = false; return;}

        dfs(l->left,r->right);
        dfs(l->right,r->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return 1;

        dfs(root->left,root->right);
        return ans;
    }
};