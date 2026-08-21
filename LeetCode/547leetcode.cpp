class Solution {
public:

  void dfs(int node,vector<vector<int>>& isConnected, vector<int>&vis,int n){
       vis[node]=1;
      for(int j=0;j<n;j++){
if(isConnected[node][j]==1&&!vis[j]){
    vis[j]=1;
    dfs(j,isConnected,vis,n);
}

      }

  }
  
    int findCircleNum(vector<vector<int>>& isConnected) {
        // USING BFS 
        //   int n=isConnected.size();
        //   queue<int>q;
        //   int ans=0;
        //   vector<int>vis(n,0);

        //      for(int i=0;i<n;i++){      // jb index 0 se jaeag to jitne bhi isse connected honge aur ya iske neighours se connected honge sbko mar kr ayega knuki wo sb mil ker ek provinces bnaenge isiliy ans++ yha hi  
        //         if(!vis[i]) ans++;
         
        //         q.push(i);
        //          while(!q.empty()){
        //          int node=q.front();
        //          q.pop();
        //          for(int j=0;j<n;j++){  //phle 0 se start hoga fir 1 chek hoga mark hoga fir 1 wale node per ja ker dekho ki 1 se kaun connected hi agar 2 conneced hi to maar ro agar nhi to fir yhi ruk jao wapas i wale iteration se ana 
        //             if(isConnected[node][j]==1&&!vis[j]){
                       
        //                 vis[j]=1;
        //                 q.push(j);
        //             }
        //          }

        //          }

        //      }
   
        
        // return ans;

        // USING DFS RECURSION METHOD
         int n=isConnected.size();
       
          int ans=0;
          int start=0;
          vector<int>vis(n,0);
          for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i,isConnected,vis,n);
            }

          }
        //  dfs(start,isConnected,vis,n,ans);
        return ans;
    }
};