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
  bool solve(TreeNode* root,long long mnval,long long mxval){
  if(root==NULL) return true;

if(root->val<=mnval||root->val>=mxval) return false;
     return solve(root->left,mnval,root->val)&& //jb left jao to mnvalue whi long_min hi rhti hi but high value uska node ka val
           solve(root->right,root->val,mxval); //jb right jao to maxval whi rhega but min val us curr node ki value

  }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
      
        return solve(root,LLONG_MIN,LLONG_MAX);  //ek range me ye calculate krna hoga jaise ex-2 me 3 ko 5 se bada but 4 se small hona chiye 
    }
};