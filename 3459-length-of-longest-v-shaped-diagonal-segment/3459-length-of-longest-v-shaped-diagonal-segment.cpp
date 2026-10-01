class Solution {
public:
int n,m;
vector<int>dx={1,1,-1,-1};
vector<int>dy={1,-1,-1,1};
int dp[500][500][4][2];
int solve(int x,int y,int d,bool turn,int tar,vector<vector<int>>& grid){
    int nx=x+dx[d],ny=y+dy[d];
    if(nx<0||nx>=n||ny<0||ny>=m||grid[nx][ny]!=tar)return 0;
    if(dp[x][y][d][turn]!=-1)return dp[x][y][d][turn];
    int res=solve(nx,ny,d,turn,2-tar,grid);
    if(turn)res=max(res,solve(nx,ny,(d+1)%4,0,2-tar,grid));
    return dp[x][y][d][turn]=1+res;
}
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n=grid.size(),m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=1)continue;
                for(int d=0;d<4;d++){
                    ans=max(ans,1+solve(i,j,d,1,2,grid));
                }
            }
        }
        return ans;   
    }
};