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
    
    int ans = INT_MAX;int pre = INT_MAX;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        
        dfs(root->left);
        ans = min(ans,abs(pre-root->val));
        pre = root->val;
        dfs(root->right);


    }

    int getMinimumDifference(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};