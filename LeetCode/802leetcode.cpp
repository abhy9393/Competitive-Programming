class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            vector<int>safenode;
int n=graph.size();
            // define indegree
            vector<int>Indegree(n,0);
            // reverse the graph
             vector<vector<int>>Revgraph(n);
             for(int i=0;i<graph.size();i++){
// i->it aesa hi abhi initial ex- 0-{1,2} it point to 1 
// after reverse it->i ab 1->{0} jb hoga tb indegre[0]++ mtlb 1 hua indegree 0 ka fir 2->{0} fir indegree[0]++ hua tb fir increase hua ab 2 ho gya means jitni baar touch hoga utna increase hoga
                for(auto it:graph[i]){
                    Revgraph[it].push_back(i);
                    Indegree[i]++;
                }
             }

            //  use queue and here push forst terminal node which indegree is 0 initially
            queue<int>q;
            for(int i=0;i<n;i++){
                if(Indegree[i]==0){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int node=q.front();
                q.pop();
                safenode.push_back(node);

                for(auto it:Revgraph[node]){
                     Indegree[it]--;  //jis node ki taraf arrow hi usko phle ek se indegree decrement kro
                     if(Indegree[it]==0){
                        q.push(it);
                     }
                }
            }
            sort(safenode.begin(),safenode.end());
            return safenode;
    }
};