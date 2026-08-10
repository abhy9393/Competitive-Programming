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
 TreeNode*  buildtree(vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie, unordered_map<int,int>&mpp){
     if(ps>pe||is>ie) return NULL;  //jb gap na rhe 2 node ke beeech means no remaining node
        TreeNode* node=new TreeNode(preorder[ps]); //create root node which is preorder starting node 
    //   abb left and right part ka gap find krna hi ki left me kitna remain hi and right me wo inorder ke root locationn se decide hoag
    int inroot=mpp[preorder[ps]]; //root node ka posittion in inorder
    int leftgap=inroot-is; // inorder me leftremaining isi se right gap bhi nikal jaega but hme right gap ka starting index bejna hoga again to inroot+1 

    node->left=buildtree(preorder,inorder,ps+1,leftgap+ps,is,inroot-1,mpp);
    node->right=buildtree(preorder,inorder,leftgap+ps+1,pe,inroot+1,ie,mpp);
    
 return node;
 }
   
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          int n=preorder.size();
          int m=inorder.size();
          if(n!=m) return NULL;
          unordered_map<int,int>mpp;
          for(int i=0;i<n;i++) mpp[inorder[i]]=i;
         return buildtree(preorder, inorder,0,n-1,0,m-1,mpp);

    }
};