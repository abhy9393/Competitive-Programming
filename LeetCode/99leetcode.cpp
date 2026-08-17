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
    TreeNode*first; //ab parameter dene ki jarurat nhi 
    TreeNode*middle;
    TreeNode*last;
    TreeNode*prev;

public:
     void Inorder(TreeNode* root){
     if(root==NULL) return;

  Inorder(root->left);
 if(prev!=NULL&&prev->val>root->val){//first voilation come yha order toot gya 
  if(first==NULL) {
    first=prev; //jo bada hua hi usko first bna do
    middle=root; //jo abhi current hi isko middle
  }
  else{ //agar second baar aya to
    last=root;
  }
 }

  prev=root; //jb tk increasing order me chl rh tb rk every node ko prev bnate rhoo 
   Inorder(root->right);

     }
       
    void recoverTree(TreeNode* root) {
            first=middle=last=prev=NULL;
            Inorder(root);  //use inorder always iterate bst in sorting increasing order
            if(first&&last) swap(first->val,last->val);  //jb dono voilations adjacent na ho ex- 2 3 4 8 6 7 5 here 8 first=8 and last=5 and middle 6 hi 
            else swap(first->val,middle->val);//jb adjacent ho ex-  3 8 7  10 15 20 25 yha 8 first and middle 7 hi but last null hi 
 
       
    }
};
