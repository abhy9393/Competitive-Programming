/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
int countnode(struct Node*root){
    if(root==NULL) return 0;
    int ans=1+countnode(root->left)+countnode(root->right);
    return ans;
}
bool IsCBT(struct Node*root,int idx,int count){
    if(root==NULL){ //means left or right NULL ho gye no further exist
    
        return true;
    }
    if(idx>=count) return false;
    else{
        bool left=IsCBT(root->left,2*idx+1,count);
        bool right=IsCBT(root->right,2*idx+2,count);
         
        return (left&&right);
    }
    
    
}
  bool isMaxheap(struct Node*root){
      if(root->left==NULL&&root->right==NULL){//if leaf node means left right does not exist
          return true;
      }
    else  if(root->right==NULL){
          return root->data>root->left->data;
      }
      return (root->data > root->left->data&&
     root->data > root->right->data && isMaxheap(root->left)&&isMaxheap(root->right));
  }

class Solution {
  public:
    bool isHeap(Node* tree) {
        // code here
        int idx=0;
    int totalnode=countnode(tree);
    if(IsCBT(tree,idx,totalnode)&&isMaxheap(tree)){ 
        return true;
    }
    else return false;
    }
};