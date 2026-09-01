class Solution {
  public:
  
    void dfs(int node,  vector<int>&vis,    vector<vector<int>>&adj,stack<int>&st){
        
        vis[node]=1;
         for(auto it:adj[node]){
             if(!vis[it]){
                 dfs(it,vis,adj,st);
             }
         }
         st.push(node); 
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        // Topological orders possible in only  Directed Acyclic Graph (DAG) 
        vector<vector<int>>adj(V); 
            vector<int> ans;
        vector<int>vis(V,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v); //because it is directed graph so
        }
         
        stack<int>st;  //here we use stack beacuse isme hme jidhar arrow hi usko jisse connected hi use bad ana chiy ex- 2->4 to 4 se phle 2 khi store ona chiue so we use stack 

        
         for(int i=0;i<V;i++){  // call dfs every node jis node ka dfs complete ho jae fir last me usko stack me bej do
             if(!vis[i]){
                 dfs(i,vis,adj,st);
             }
         }
        
        while(!st.empty()){ 
             ans.push_back(st.top());
             st.pop();
        }
          return ans;
        
    }
};