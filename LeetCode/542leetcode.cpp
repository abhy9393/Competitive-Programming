class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
int dist=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,0)); //ye distance store krega yha hme 1 se 0 ka disance pta krna hi 
          queue<pair<pair<int,int>,int>>q; //because of distance from 1 to 0 so we used opposite concept 0 ke 4 direction me chek krte jae jha jha 1 mile whi distance me count krte chle 
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){  
                    q.push({{i,j},dist}); //pop out ke baad sitance marked
             vis[i][j]=1;

                }
            }
           }
       int drow[4]={-1,0,+1,0};
       int dcol[4]={0,-1,0,+1};
           while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int x=q.front().second;
            q.pop();
            distance[row][col]=x;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&vis[nrow][ncol]==0&&mat[nrow][ncol]==1){  
                    vis[nrow][ncol]=1;
                     q.push({{nrow,ncol},x+1});

                }
            }

           }
           return distance;
    }
};