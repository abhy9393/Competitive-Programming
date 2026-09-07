class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
// time complexity =O(ElogV);
        vector<vector<pair<int,int>>> adj(n);
        vector<int>dist(n,INT_MAX);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            adj[u].push_back({v,wt});  //directed graph
        }
    //    here we dont use priority queue because when we use pq with first store cost then optimal path not able to find and if we store step first in pq then not any use of pq becasuse every time step+1 and it not take any value in plus  so large step always on top and previous topic we seen for unit increment use queue less time complexity
  
  queue<pair<int,pair<int,int>>>q;//it store {stops,{node,cost}}
    q.push({0,{src,0}});
    dist[src]=0;
    while(!q.empty()){
  int node=q.front().second.first;
  int stops=q.front().first;
  int cost=q.front().second.second;
  q.pop();
    if(stops>k) continue;  //because stops+-1 jo hoga wo k ke equal hoga lekin knuki directed graph hi to kai sre path se jo k se kam honge stops se aa skta hi lekin unmse se kis k se kam stops me minimum cost hi wo lene hi isiliy rukna nhi hi
    for(auto it:adj[node]){
     if(dist[it.first]>it.second+cost&&stops<=k) {  //yha stops+1 isiliye chek nhi kiye knuki stops alredy k se ek jada hi rhta hi 
       dist[it.first]=it.second+cost;
       q.push({stops+1,{it.first,it.second+cost}});
     }

    }

    }
    

   if(dist[dst]==INT_MAX) return -1;
   return dist[dst];
    }
};