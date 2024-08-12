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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
               queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> v;

        if(root == NULL) return {};
        TreeNode* curr = root;
        q.push(curr);
        TreeNode* last = curr;

        while(!q.empty()){
            TreeNode* del = q.front();
            q.pop();
            
            if(del->left != NULL){
                q.push(del->left);
            }
            if(del->right != NULL){
                q.push(del->right);
            }
            
            if(last == del){
               v.push_back(del->val);
               if(ans.size() % 2 == 0){
                   ans.push_back(v);
               }
               else{
                   reverse(v.begin(),v.end());
                   ans.push_back(v);
               }
        
               v.clear();
               if(q.empty()) break;
               last = q.back();
            }
            else{
                v.push_back(del->val);
            }
        }
        
        return ans;
    }
};