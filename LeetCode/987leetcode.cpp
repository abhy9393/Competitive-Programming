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

//  T.C=O(nlogn)  S.C=O(n)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // store node,coloum,level for this we use queue yha se one by one pop krenge
        queue<pair<TreeNode*,pair<int,int>>>todo;

        // define map ds because we final access by using node in asending order like -1 node first 
        map<int,map<int,multiset<int>>>mpp; //isme phla key hoga column iske liye value ka work krega level aur level key ka work kreag uss node ki value ke liye {col,{level,node->val}}  ex- (0,2) pr 2 vlue hi 5 and 6  to ye dono isi position pr sorted me store honge
     todo.push({root,{0,0}}); //initialize first 0 is column and second is level
     while(!todo.empty()){
        auto it=todo.front();
        todo.pop();
         TreeNode* node=it.first;
         int x=it.second.first;
         int y=it.second.second;
          mpp[x][y].insert(node->val);

          if(node->left) todo.push({node->left,{x-1,y+1}});
          if(node->right) todo.push({node->right,{x+1,y+1}});

     }
 vector<vector<int>> ans;
     for(auto it:mpp){
       vector<int>temp; // knuki kisi kisi map pe 2 se jada value bhi ho skti hi jinhe eks sath ans me push krna hota hi ex {5,6}
         for(auto q:it.second){
            temp.insert(temp.end(),q.second.begin(),q.second.end());
         }
         ans.push_back(temp);
     }



return ans;
    }
};