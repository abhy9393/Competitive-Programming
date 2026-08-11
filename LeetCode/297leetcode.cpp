/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
   string serialize(TreeNode* root) {
    if (root == NULL) return "";

    queue<TreeNode*> q;
    q.push(root);

    string ans;

    while (!q.empty()) {  // for loop nhi use krenge knuki ek hi vector as string hi
        TreeNode* node = q.front();
        q.pop();

        if (node == NULL) {
            ans += "# ";
            continue;
        }


ans+=to_string(node->val); //we use to_string beacuse -'0' wala concept only one digit 0 to 9 ke liye valud hi but yha -1000 s ehi to negative me -26 hi to isko seprate store krna hoga like "-25" char-'0' se ye - alag 2 alag jo ki galat
ans+=" "; //give extra space because acces ex- 2#25 to ye 25 ek digit hi to indexing wrong ho jagea so isisliye

        q.push(node->left);
        q.push(node->right);
    }

    return ans;
}

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       if(data=="") return NULL;

       stringstream ss(data); //it coverts whole char in form of stirng a single column 
       string val;
       ss>>val; //ye cin jaise hota hi jb jb call hoga  next pointer pe move kr jaega ex 1 2 3 to ss>val=1 ss>val=2 ..
       queue<TreeNode*>q;
     TreeNode* root=new TreeNode(stoi(val));
     q.push(root);
     while(!q.empty()){
     TreeNode* node= q.front();
     q.pop(); 
       
    //    left child
       ss>>val;
       if(val!="#"){
          node->left=new TreeNode(stoi(val));  //node ka left  baki # hone pr automatic null le lega
  q.push(node->left);

       }

       ss>>val; //right child 
       if(val!="#"){
        node->right=new TreeNode(stoi(val));
        q.push(node->right);
       }

     }
  return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));