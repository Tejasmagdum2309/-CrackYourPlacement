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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int mxwidth = 1;
        if(root == NULL) return mxwidth;
        TreeNode* last = root;
        q.push({root,0});

        while(!q.empty()){
            TreeNode* x = q.front().first;
            int w = q.front().second;

            q.pop();

            if(x->left != NULL){
                q.push({x->left,(long long)2 * w + 1});
            }
            if(x->right != NULL){
                  q.push({x->right,(long long)2*w+2});
            }

            if(last == x){

                if(q.empty()) break;
                
                mxwidth = max(mxwidth,(q.back().second -  q.front().second) + 1 );
 cout<<mxwidth<<"--";
                last = q.back().first;;
            }
        }

        return mxwidth;
    }
};