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
// T.C=O(N) using level wise traversal
    int maxDepth(TreeNode* root) {
    //     int count=0;

    //     queue<TreeNode*>q;
    //     if(root==NULL) return 0;
    //     q.push(root);
    //     while(!q.empty()){
    //     int n=q.size();
    //     count++;
    //     for(int i=0;i<n;i++){

    //        TreeNode* node=q.front();
    //        q.pop();
    //        if(node->left!=NULL) q.push(node->left);
    //        if(node->right!=NULL) q.push(node->right);
    //     }


    //     }
    //     return count;

    // OPTIMAL USING RECURSION T.C=O(HEIGHT)

    if(root==NULL) return 0;

    int LH=maxDepth(root->left);
    int RH=maxDepth(root->right);
    return 1+max(LH,RH);
    }
};