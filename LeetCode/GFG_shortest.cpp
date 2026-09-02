class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
         vector<vector<int>>adj(V);
         vector<int>dist(V,INT_MAX);  //initiallly infinite distane maan ker chlenge 
         for(int i=0;i<edges.size();i++){
             int u=edges[i][0];
             int v=edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
             
         }
         
        queue<pair<int,int>>q; //store starting siurce node with 0 distance initially
        q.push({src,0});  
        dist[src]=0;
        while(!q.empty()){
            int node=q.front().first;
            int x=q.front().second;
            q.pop();
        //yha dist ko update nhi krenge knuki maan lo jb 7 aur 8 dono queue ke andar honge us time 8 upate nhu hua rhega to 7 aa ker for se 8 ko push kr dega queue me 
        for(auto it:adj[node]){
            if(dist[it]==INT_MAX){
                  dist[it]=x+1; //yha update krenge 
                q.push({it,x+1});
            }
        }
            
        }
        
     if(dist[dest]==INT_MAX) return -1;
        
        return dist[dest];
    }
};
