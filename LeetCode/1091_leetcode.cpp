class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]!=0) return -1;
          vector<vector<int>>vis(n,vector<int>(m,0));
       vis[0][0]=1;
     int dr[8] = {-1,-1,-1,0,0,1,1,1}; //phle -1 -1 -1 ye hi upper kaise bhi jao digonaly ya up row hmesa -1 hoga fir mid me 0 rhega fir down kaise bhi jao row hmesa  +1 hoga
int dc[8] = {-1,0,1,-1,1,-1,0,1}; //coloumn  jb left diagonal move krogge to decrease hoga -1 mid up 0 right diag +1 hoga mid me left me -1 aur right +1 and down left diag -1 hoga down 0 hoga down right +1 hoga 
        // define queue which store {{row,col},step}  ek move per 8 direction me sare same step count ho
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});// starting step is 1 maan lo agar 1 rhe n to 1 whi step
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            if(row==n-1&&col==m-1&&vis[row][col]==1){
                return step;
            }
             for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==0&&vis[nrow][ncol]==0){
                     vis[nrow][ncol]=1;
                     q.push({{nrow,ncol},step+1});
                }
             }

        }



       
      return -1;
        
    }
};