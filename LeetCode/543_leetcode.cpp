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

int maxdiameter(TreeNode* root,int &maxi){
    if(root==NULL) return 0;

       int  LH=maxdiameter(root->left,maxi);
       int  RH=maxdiameter(root->right,maxi);
       maxi=max(maxi,LH+RH);

       return 1+max(LH,RH);
    
}
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
       maxdiameter(root,maxi);
         return maxi;
    }
};