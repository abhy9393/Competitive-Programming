class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // T.C=O(n*m) and S.C=O(n*m)
        int n=grid.size();
        int m=grid[0].size();
      
int mxt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));  //mtlb ki row ko 0 se initlize krte chle jao n row tk
        // for level order traversal means BFS
        // {{r,c},t}   row,col,time
        queue<pair<pair<int,int>,int>>q; 
        // ab sbse phle time 0  le ker jitnw 2 means damage hi unko queue me push krunga
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]==2){
                    q.push({{r,c},0});
                    vis[r][c]=2;
                }
                else{
                    vis[r][c]=0;
                }
            }
        }
 //create two row and col vector array for cheking all 4 directions 
        int drow[4]={-1,0,+1,0}; //ye row ka hi
        int dcol[4]={0,+1,0,-1};// ye column ka hi 
    while(!q.empty()){
        auto it=q.front();
        int r=it.first.first;
        int c=it.first.second;
        q.pop();
        int sec=it.second;
        mxt=max(mxt,sec);
 // boundary condition- row<n col<m row>=0 and col>=0  main conditio- vis[nrow][ncol]==0 rhe and grid[nrow][ncol]=1 n means neighbours  rhe tb hum time increase krenge;
    for(int i=0;i<4;i++){
int nrow=r+drow[i]; //row move
int ncol=c+dcol[i];//col move
  if(nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&vis[nrow][ncol]==0&&grid[nrow][ncol]==1){
     q.push({{nrow,ncol},sec+1});
      vis[nrow][ncol]=2;//marked 2 because its neighbour of previous 2 which value in grid is 1 so now it 2 
  }
    }
    }
    // chek krte hi ki kya vis[r][c]!=2 and grid[i][j]=1 mtlb aesa koi 1 rhe gya grid me jiska vis me 2 nhi hua gar aesa hi to -1 return kr do mtlb ki wo damage nhi ho paya
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2&&grid[i][j]==1){
                return -1;
            }
        }
    }
    return mxt;
    }
};