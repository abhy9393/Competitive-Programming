class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // IT GIVES TLE 1110/1113 TEST CASES        // Code here
        // vector<int>dist(V,INT_MAX);
        // int n=edges.size();
        // vector<vector<pair<int,int>>>adj(V);
        //   for(int i=0;i<n;i++){
        //       int u=edges[i][0];
        //       int v=edges[i][1];
        //       int wt=edges[i][2];
        //       adj[u].push_back({v,wt}); //undorected graph hi
        //       adj[v].push_back({u,wt});
              
        //   }
        //   queue<pair<int,int>>q;
        //   q.push({src,0});
        //   dist[src]=0;
        //   while(!q.empty()){
        //       int node=q.front().first;
        //       int x=q.front().second;
        //          q.pop();
        //          for(auto it:adj[node]){
        //              if(dist[it.first]>x+it.second){
        //                  dist[it.first]=x+it.second;
        //                  q.push({it.first,x+it.second});
        //              }
        //          }
               
        //   }
        //   return dist;
        
        // OPTIMAL CODE USING PRIORITY QUEUE ye minimum distance wale ko phle nikal lega 
          vector<int>dist(V,INT_MAX);
        int n=edges.size();
        vector<vector<pair<int,int>>>adj(V);
          for(int i=0;i<n;i++){
              int u=edges[i][0];
              int v=edges[i][1];
              int wt=edges[i][2];
              adj[u].push_back({v,wt}); //undorected graph hi
              adj[v].push_back({u,wt});
              
          }
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
          pq.push({0,src}); //yha pq me {dist,node} store hoga
          dist[src]=0;
          while(!pq.empty()){
              int node=pq.top().second;
              int x=pq.top().first;
                 pq.pop();
                 
                 for(auto it:adj[node]){
                     if(dist[it.first]>x+it.second){
                         dist[it.first]=x+it.second;
                         pq.push({x+it.second,it.first});
                     }
                 }
               
          }
          return dist;
        
    }
};