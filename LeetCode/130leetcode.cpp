class Solution {
public:
// T.C-O(n*m)  S.C=O(n*m)
    void solve(vector<vector<char>>& board) {
        // logic yhi hi ki sare boundary ke O ko store kro fir unke sare possible direction me chek krte jao agr koi unse touch O mile to udhar move kro jb tk possible hi knuki usi raste se aur o aa skte hi fir vis me marked kro
         int n=board.size();
         int m=board[0].size();
         queue<pair<int,int>>q;
          vector<vector<int>>vis(n,vector<int>(m,0));
        //   store left+right boundary  isme column dono constant rhte hi ek bar 0 column ek bar last
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
            q.push({i,0});
            vis[i][0]=1;
            }

            if(board[i][m-1]=='O'){
    q.push({i,m-1});
     vis[i][m-1]=1;
            }
        }
    


        // store up+down boundary
        for(int i=0;i<m;i++){ //yha row constant hi to column me move krenge 
            if(board[0][i]=='O'){
            q.push({0,i});
            vis[0][i]=1;
            }

            if(board[n-1][i]=='O'){
    q.push({n-1,i});
     vis[n-1][i]=1;
            }
        }
int drow[4]={-1,0,+1,0};
int dcol[4]={0,+1,0,-1};

     while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
         for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
if(nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&board[nrow][ncol]=='O'&&vis[nrow][ncol]==0){
    q.push({nrow,ncol});
    vis[nrow][ncol]=1;
}

         }
     }

    //  chek kro ki kaun kaun board me 0 hi aur vis me bhi 0 hi marked nhi mtlb ki ye boundary tk nhi jaenge inko x kr do
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
    if(vis[i][j]==0&&board[i][j]=='O'){
        board[i][j]='X';
    }

        }
    }
    }
};
