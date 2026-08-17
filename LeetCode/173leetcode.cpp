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
class BSTIterator {
public:
TreeNode* root;  //class ke andar initialize kiya whole code use

stack<TreeNode*> st;//yha declare krne se abb parameter me nhi dena hoga iska use reverse in order ke element store kr leneg taki jb bhi next funcion call ho ek  ek pop out kr lein
void solve(TreeNode*root){
    if(root==NULL) return;
    
    solve(root->right);
    st.push(root);
    solve(root->left);
}
    BSTIterator(TreeNode* root) {
        this->root=root;  //yha isko declare kiya
       solve(root); // ye solve function isiliye call kiya taki ek hi baar bs stack me value sari push ho nhi agar next ke andar krta to har bar call hota  har baar value push hoti pure tree ki
    }
    


    int next() {
    
        
       TreeNode*node=st.top();
       st.pop();
       return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */