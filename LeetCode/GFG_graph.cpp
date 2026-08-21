class Solution {
  public:
  
  
    void dfs(int node,vector<vector<int>>& adj,vector<int>&vis){
                  vis[node]=1;
                  for(auto it:adj[node]){
                      if(!vis[it]){
                          vis[it]=1;
                          dfs(it,adj,vis);
                      }
                  }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
         vector<vector<int>>adj(V);///maan lo sare ek dusre connected ho gye to pura v.
        //  yha edge diya hi to phle ise adjency list me convert krenge  ki kis node ka neighiur kaun hi jaise u=1 v=4 to adj[1]=4 and adj[4]=
         int n=edges.size();
         
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
         
         int start=0;
         vector<int>vis(V,0);
         int ans=0;
         for(int i=0;i<V;i++){
              if(!vis[i]){ //0 se v tk sare value present honge isiliye i se hi kro 
                  
               ans++;
         dfs(i,adj,vis);
              }
         }
         
        return ans;
    }
};