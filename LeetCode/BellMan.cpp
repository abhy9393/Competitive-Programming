class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here   T.C=O(V*E)
          vector<int>dist(V,1e8);
          dist[src]=0;
          for(int i=0;i<V-1;i++){ //becasuse 0 alredy marked hota hi na
               
               for(auto it:edges){  //har step per value reduce chek hoti hi 
                   int u=it[0];
                   int v=it[1];
                   int wt=it[2];
                   if(dist[u]!=1e8&&dist[u]+wt<dist[v]){ //jb bhi us particular dit per less value milti hi tb updation hota hi
                       dist[v]=dist[u]+wt;
                   }
               }
          }
          
        //   chek negative cycle detection n-1 times hum chek kr chuke hi ab agar iske baad ek air chlayenge agr ism bhi value reduce hui t pakka cycle hi
        for(auto it:edges){
              int u=it[0];
                   int v=it[1];
                   int wt=it[2];
                     if(dist[u]!=1e8&&dist[u]+wt<dist[v]){
                       return {-1};
                   }  
        }
        return dist;   
    } 
};
