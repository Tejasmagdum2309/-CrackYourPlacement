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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        queue<TreeNode*> q;
        if(root == NULL) return {};
        TreeNode* last = root;
        q.push(root);
        
        
        while(!q.empty()){
            TreeNode* d = q.front();
            q.pop();

            if(d->left != NULL){
                q.push(d->left);
            }

            if(d->right != NULL){
                q.push(d->right);
            }

            if(last == d){
                
                ans.push_back(d->val);
               
                if(q.empty()) break;
                last = q.back();
            }
            
        }

        return ans;
    }
};