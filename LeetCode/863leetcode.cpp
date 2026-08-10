/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
     void makeparent(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent){
          queue<TreeNode*>qu;
          qu.push(root);
          while(!qu.empty()){
             TreeNode*curr=qu.front();
                 qu.pop();
                 if(curr->left){
parent[curr->left]=curr; 
     qu.push(curr->left);
                 } 
                 if(curr->right){
                    parent[curr->right]=curr;
                      qu.push(curr->right);
                 }


          }


     }
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
         unordered_map<TreeNode*,TreeNode*>parent;  //iska use krte hi upword jane ke liye because we access left and right by using left right pointer
         makeparent(root,target,parent);
         queue<TreeNode*>q;
         unordered_map<TreeNode*,bool>visited;
         int dist=0;
   visited[target]=true;
       q.push(target);
       while(!q.empty()){
        int n=q.size();
        if(dist==k) break;
        dist++;
             for(int i=0;i<n;i++){
             TreeNode* node=q.front();
             q.pop();
             if(node->left&&!visited[node->left]){
                q.push(node->left);
                visited[node->left]=true;
             }
             if(node->right&&!visited[node->right]){
                q.push(node->right);
                visited[node->right]=true;
             }
             if(parent[node]&&!visited[parent[node]]){  //ab upper jane ke liye jo iska parent hi jo visited nhi hi usko push kr do aur chek ki uska parent exist krta hi ya nhi
                q.push(parent[node]);
               visited[parent[node]]=true;
             }
              

             }


       }
       while(!q.empty()){
       ans.push_back(q.front()->val);
       q.pop();

       }
 return ans;
    }
};