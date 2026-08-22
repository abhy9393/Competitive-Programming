class Solution {
  public:
  
   bool detectcycle(int start, vector<vector<int>>&adj,  vector<int>&vis){
       vis[start]=1;
          queue<pair<int,int>>q; //stores node and also its parent
          q.push({start,-1});
          
          while(!q.empty()){
              int node=q.front().first; //ab iske jo adjecent honge unke liye parent hoga
              int parent=q.front().second; //ye node ka parent hi 
              q.pop();
              for(auto it:adj[node]){
                  if(!vis[it]){
                      vis[it]=1;
                      q.push({it,node});
                  }
                  else if(it!=parent){ // maan lo koi aesa adj me element mil jo ki visited hi to ab chek krenge ki kya yha node ka parent hi 
                //   to nhi knuki ye node apne parent se hi to aya hi to
                // wo bhi adj me hoga agar wo parent na nikla aur visited already hi mtlb ki koi aur visit kr diya to cycle hoga 
                      return true;
                  }
              }
          }
          
       return false;
       
   }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int cnt=1;
        vector<int>vis(V,0);
        int n=edges.size();
           vector<vector<int>>adj(V);
           for(int i=0;i<edges.size();i++){
               
               int u=edges[i][0];
               int v=edges[i][1];
               adj[u].push_back(v);
               adj[v].push_back(u);
           }
            // maan lo multiple component ho to sb component ko chekkrna hoga
            for(int i=0;i<V;i++){ //ek node jaega apne connected component tk mark kr ayega 
                if(!vis[i]){
                   if( detectcycle(i,adj,vis)) return true;
                }
            
            }
            return false;
    }
};