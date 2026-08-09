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
public:

// T.C=O(n) S.C=O(n)
// bool getPath(TreeNode* root, TreeNode* x, vector<TreeNode*>& path){

//         if(root == NULL)
//             return false;

//         path.push_back(root);

//         if(root == x)
//             return true;

//         if(getPath(root->left, x, path) ||
//            getPath(root->right, x, path))
//             return true;

//         path.pop_back();

//         return false;
//     }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // vector<TreeNode*> path1, path2;

        // getPath(root, p, path1);
        // getPath(root, q, path2);

        // TreeNode* ans = NULL;

        // int i = 0;

        // while(i < path1.size() && i < path2.size()){

        //     if(path1[i] != path2[i])
        //         break;

        //     ans = path1[i];
        //     i++;
        // }

        // return ans;

    // to reduce extra space complexity we use only T.C=O(n) S.C=O(1)
    // left jate  rho agar p mil gya to whi p return kr do agr nhi to null fir right chek kro aagar right me q mila to q return kr do nhi to null fir jis node ke left right the jispe dono ki value left and right ki null nhi hui means whi ans hi 

    if(root==NULL||root==p||root==q){  //ya to root null ho jae ya root me p ya q koi bhi mil jae turant whi stop ho ke return kr do
 return root;
    }

     TreeNode* left= lowestCommonAncestor(root->left,p,q);
     TreeNode* right= lowestCommonAncestor(root->right,p,q);
    if(left==NULL) return right; //ek null hua to dusra rturn kro 

  else if(right==NULL) return left;
  else return root; //mtlb dono null nhi hi to yhi node hi ans hi

    }
};