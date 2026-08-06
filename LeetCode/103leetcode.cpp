
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
        // thought process using level order traversal
        vector<vector<int>> ans;
        queue<TreeNode*>q;
        if(root==NULL) return ans;
        q.push(root);
        bool left=true;
        while(!q.empty()){
          int n=q.size();
          vector<int>level(n);//alreday defined size because we dnt use push
       
            for(int i=0;i<n;i++){
                TreeNode* root=q.front();
                q.pop();

                int idx=left ? i:n-1-i;  // agar phle left se aa rhe to value left ki true hogi to i use kro means left se hi valu insert kro nhi to idx ki value n-1-i set kr do
                // level.push_back(root->val);
                level[idx]=root->val;
               
             
                if(root->left!=NULL)q.push(root->left);
                if(root->right!=NULL)q.push(root->right);
 
                
             
          }
                left=!left;
                ans.push_back(level);

         
        }
return ans;
    }
};