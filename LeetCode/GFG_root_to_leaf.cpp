/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    bool leaf(Node* root){
        return root->left==NULL&&root->right==NULL;
    }
  public:
  
  
     void DFS(Node* root,vector<vector<int>>&ans,vector<int>&temp){
            if(root==NULL) return;
            temp.push_back(root->data);
           if(leaf(root)){
               ans.push_back(temp);
            //   return  yha return us nhi krenge knuki push ke bad hi function khatam ho ajega to aage pop wala execute hi nhi higa
           }
           
           DFS(root->left,ans,temp);
                    //   temp.pop_back(); yha pop nhi krenge  knu jb right wala se return hoga to uska pop possible hi nhi hoga 
           DFS(root->right,ans,temp);
           temp.pop_back();

           
     }
  
    vector<vector<int>> paths(Node* root) {
        // code here
           vector<vector<int>> ans;
        if(root==NULL) return ans;
           vector<int>temp;
           DFS(root,ans,temp);
           return ans;
    }
};