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
    int widthOfBinaryTree(TreeNode* root) {
         if(root==NULL) return 0;
         int ans=0;
 queue<pair<TreeNode*,int>>q;
  q.push({root,0});
  int first,last=0;
  while(!q.empty()){
  int n=q.size();
  int mini=q.front().second;
  for(int i=0;i<n;i++){
    
  int idx=q.front().second-mini; //aesa isiliye krte hi taki next node ko 1 se start kr paye aur jaise maan lo koi left node ka left null ho aur right ho to fir wo mini bnega tbhi hum jo last hi usse minus krke exact width find 
  TreeNode* node=q.front().first; 
  q.pop();
   if(i==0) first=idx; //jb phla node mile
   if(i==n-1) last=idx; //aceess only last ko kr rh

   if(node->left)  q.push({node->left,1LL*2*idx+1});
   if(node->right)  q.push({node->right,1LL*2*idx+2});
  }

ans=max(ans,last-first+1);
  }
 return ans;
    }
};