class Solution {
    int timer=1;
public:
// tmime comlexity O(v+2E) and S.C=O(V+2E)
void dfs(int node,int parent,vector<vector<int>>&bridge,vector<int>&low,vector<int>&tin,vector<vector<int>>&adj, vector<int>&vis){
     vis[node]=1;
   low[node]=tin[node]=timer;
   timer++;
    for(auto it:adj[node]){
        if(it==parent) continue; //knuki adj me uska parent bhi ayega na to us per hme jana nhi hi aage chek krna hi
        if(vis[it]==0){
           dfs(it,node,bridge,low,tin,adj,vis);
              low[node]=min(low[node],low[it]);  //recursion jb visited milne ke baad jb low[node] ek ka set ho jaega fir waps ayega fir baki jisse wo wha tk gya th sbke low of node ko update krega
              if(low[it]>tin[node]){  //agr maan lo jo parent node th uske bagal wala koi node ki low value mtlb minimu jitna step me wo kisi node per phuch skta hi wo badi ho gyi parent node ke tin jo ki maximum value hi to means wo kbhi parent node tk nhi phuch payega to ye bridge hta do 
                bridge.push_back({it,node});
              }
         }
        else{
          low[node]=min(low[node],low[it]); //isk chlne ke bad recursion wapas jaega 
        }
    }

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>vis(n);
vector<vector<int>>bridge; 
  vector<int>low(n);
  vector<int>tin(n); //ye ek bar ste hoga fir update nhi hoga
   vector<vector<int>>adj(n);
   for(auto it:connections){
    adj[it[0]].push_back(it[1]);
    adj[it[1]].push_back(it[0]);
   }

  dfs(0,-1,bridge,low,tin,adj,vis);


 return bridge;
    }
};