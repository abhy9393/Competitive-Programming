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
int  findmaxsum(TreeNode* root,int &maxsum){
    if(root==NULL) return 0;

    int leftsum=findmaxsum(root->left,maxsum); //ek branch se jha umbrella shape bnta hi uske left se hmesa leftsum deta hi
    int rightsum=findmaxsum(root->right,maxsum);
    if(leftsum<0){ //agar kisi branch se negative aa rha to wo consider krne se aur minimum ho jaega
        leftsum=0;
    }
    if(rightsum<0){
        rightsum=0;
    }
 maxsum=max(maxsum,leftsum+rightsum+root->val); //leftsum and rightsum me uske root ka val add kr do

     return root->val+max(leftsum,rightsum);
}
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        findmaxsum(root,maxsum);
        return maxsum;
    }
};