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

void showright(TreeNode* root,int level, vector<int>&ans){
  //here we traverse in root->right->left aur jb level==ans.size() tbhi value ans me add krenge
    if(root==NULL) return;
//  base case
    if(level==ans.size()) ans.push_back(root->val);
      showright(root->right,level+1,ans); //always increase level by 1
      showright(root->left,level+1,ans);

}
    vector<int> rightSideView(TreeNode* root) {
            vector<int>ans;
            
             showright(root,0,ans);
             return ans;
    }
};