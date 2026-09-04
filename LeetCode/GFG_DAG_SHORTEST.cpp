class Solution {
  public:
  
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
          vis[node]=1;
          
          for(auto it:adj[node]){
              if(!vis[it]){
                  
                  dfs(it,vis,adj,st);
              }
          }
          st.push(node);
    }
  
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        // code here
           
            
            // step-1 first find toposort using dfs stack
            int n=edges.size();
                vector<int>vis(V,0);
      stack<int>st;
                 vector<vector<int>>adj(V);
                 for(int i=0;i<n;i++){
                     int u=edges[i][0];
                     int v=edges[i][1];
                     adj[u].push_back(v);
                 }
                 
                 for(int i=0;i<V;i++){
                     if(!vis[i]){
                         dfs(i,vis,adj,st);
                     }
                 }
                 
                //  step -2 ek ek element stack se nikalo aur fir usse shortest dist calculate kro
                // isme adj list me pair store honge jo uss node se connected node aur uske weight ko ko store krenge 
                // stack use isiliye use kiye knuki topo sort me source node se dst node tk ka sequence rhta h
                   vector<int>ans;
                   vector<vector<pair<int,int>>>list(V);
                    vector<int>dist(V,INT_MAX);
                    // source node ka distance hmesa 0 hoga baki iske aage sbko ditance calulate hogi
                    // yha start 0 s hi
                        for(int i=0;i<n;i++){
                            int src=edges[i][0];
                            int node=edges[i][1];
                            int wt=edges[i][2];
                            list[src].push_back({node,wt});
                        }
                       
                       dist[0]=0;  //yha particular question me mentioned hi ki 0 hhmesa source node hoga to ye jaruri nhi hi ki stack ke top per bhi 0 aye beech m bhi 0 aa skta hi to caluclatio beech se hogi
                       while(!st.empty()){
                           int node=st.top();
                           int x=dist[st.top()];
                           st.pop();
                           if(dist[node]==INT_MAX) continue; //maaan lo stack ke top me 6 5 0 .. fir age aya to 6 aur 5 to rechable hi nhi hi wo 0 se piche hi to inhe skip kro knuki hme 0 se distance calculate kni hi
                           for(auto it:list[node]){
                               if(dist[it.first]>x+it.second){ //yha INT_MAX wali condition nhi rhega knuki wo undirected me hota tha wha 1 maan ker chkte the to hmesa shortst hi milta th bu yha value di hi to chek krna hoga hmesa 
                                   dist[it.first]=x+it.second;
                               }
                           }
                       }
                       for(int i=0;i<V;i++){
                           if(dist[i]==INT_MAX){
                               ans.push_back(-1);
                           }
                           else{
                               ans.push_back(dist[i]);
                           }
                       }
                       
                       
               return ans;         
    }
};
