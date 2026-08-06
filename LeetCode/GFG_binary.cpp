/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
   bool isleafnode(Node *root){
       return root->left==NULL&&root->right==NULL;
   }
  
  public:
   
      void addleftnode(Node *root, vector<int>&ans){
            Node*curr=root->left; 
            while(curr){
                if(!isleafnode(curr))  ans.push_back(curr->data); // add tbhi krna hi  jb tk leaf node na ho
                if(curr->left) curr=curr->left;  //fir agar next leaf node ho to curr ko wha kr do
                else curr=curr->right; //agar left na present ho to uss left wale brance ke kisi specific node pe ho to uska left na ho to fir right pe ao
                    
                  
            }
          
            
          
      }
      void addrightnode(Node *root, vector<int>&ans){
          vector<int>temp;  //take extra because it add  after the leaf and oppsite add krna hoga ans me knuki arrow left se aa rha aur niche se ho ke U shape me ja rh
            Node*curr=root->right;
            while(curr){
                if(!isleafnode(curr))  temp.push_back(curr->data);
                if(curr->right) curr=curr->right;
                else curr=curr->left;
                    
                 
                
            }
            
           for(int i=temp.size()-1;i>=0;i--){
               ans.push_back(temp[i]);
           }
            
          
          
      }
      void addleafnode(Node *root, vector<int>&ans){
          
          if(isleafnode(root)) ans.push_back(root->data);
          
          if(root->left) addleafnode(root->left,ans); //jb tk leafnode  na aa jae niche jate rho
          if(root->right) addleafnode(root->right,ans);
          
          
      }
    vector<int> boundaryTraversal(Node *root) {
        // code here
         vector<int>ans;
         
        if(root==NULL) return ans;
         if(!isleafnode(root)) ans.push_back(root->data); //beacuse leaf node hone per wonaddleaf wale me already count ho jaega
         
         addleftnode(root,ans);
         addleafnode(root,ans);
         addrightnode(root,ans);
         
         return ans;
        
        
    }
};