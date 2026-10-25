class Solution {
public:
vector<int>dr={0,-1,0,1};
vector<int>dc={1,0,-1,0};
void dfs(int r,int c,vector<vector<int>>&vis){
    int n=vis.size(),m=vis[0].size();
    vis[r][c]=true;
    for(int i=0;i<4;i++){
        int nr=r+dr[i],nc=c+dc[i];
        if(nr<0||nr==n||nc<0||nc==m||vis[nr][nc])continue;
        dfs(nr,nc,vis);
    }
}
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n<3||m<3)return 0;
        vector<vector<int>>vis=grid;
        for(int i=0;i<n;i++){
            if(!vis[i][0])dfs(i,0,vis);
            if(!vis[i][m-1])dfs(i,m-1,vis);
        }
        for(int i=1;i<m-1;i++){
            if(!vis[0][i])dfs(0,i,vis);
            if(!vis[n-1][i])dfs(n-1,i,vis);
        }
        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(!vis[i][j]){
                    dfs(i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};