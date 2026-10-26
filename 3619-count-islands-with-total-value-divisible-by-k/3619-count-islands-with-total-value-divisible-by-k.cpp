class Solution {
public:
int n,m;
vector<int>dr={1,0,-1,0};
vector<int>dc={0,1,0,-1};
int dfs(int r,int c,vector<vector<int>>&grid,int k,vector<vector<bool>>&vis){
    vis[r][c]=1;
    int res=grid[r][c]%k;
    for(int i=0;i<4;i++){
        int nr=r+dr[i],nc=c+dc[i];
        if(nr<0||nr==n||nc<0||nc==m||vis[nr][nc]||grid[nr][nc]==0)continue;
        res=(res+dfs(nr,nc,grid,k,vis))%k;
    }
    return res%k;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j])continue;
                if(!vis[i][j]){
                    int x=dfs(i,j,grid,k,vis);
                    if(x==0)ans++;
                }
            }
        }
        return ans;
    }
};