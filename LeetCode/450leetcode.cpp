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

    // thought: jis node ko delete krna hi wha tk jao according to condition fir uss node ke right ja ke jo sbse small node ho usi ko return kro ye using solve() function knuki smallest hmesa left me hoga fir iski value key value wale node ko ssign kr do fir iss smallest node pe ja kr jo ki uss key wale node ke right me hi hoga ja ke delete kr do
    
    
public:

      TreeNode* solve(TreeNode*node){
     
        if(node==NULL) return NULL;

        if(node->left==NULL) return node;
         return solve(node->left);
        
      }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
          
       if(root->val==key){    
         if(root->left==NULL) return root->right;
         if(root->right==NULL) return root->left;
        TreeNode* temp=solve(root->right);
          root->val=temp->val;
          root->right=deleteNode(root->right,temp->val);
// return root;
       }
        if(root->val<key){ 
            root->right=deleteNode(root->right,key);

        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);

        }
      
       
        return root;
    }
};