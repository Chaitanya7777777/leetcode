class Solution {
public:
long long int mod=1e9+7;
long long int solve(int i,int j,vector<vector<int>>& grid,vector<vector<long long int>>&dp){
    if(i<0||j<0)return 0;
    if(i==0&&j==0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    long long int res=0;
    if(i>0){
        int ni=i,nj=j;
        if(grid[i-1][j]==1){
            int up=1,left=0;
            while(i-up>=0&&j-left>=0&&grid[i-up][j-left]==1){
                i=i-up;
                j=j-left;
                swap(up,left);
            }
            if(i-up>=0&&j-left>=0)res+=solve(i-up,j-left,grid,dp);
        }
        else res+=solve(i-1,j,grid,dp);
        i=ni;
        j=nj;
    }
    if(j>0){
        int ni=i,nj=j;
        if(grid[i][j-1]==1){
            int up=0,left=1;
            while(i-up>=0&&j-left>=0&&grid[i-up][j-left]==1){
                i=i-up;
                j=j-left;
                swap(up,left);
            }
            if(i-up>=0&&j-left>=0)res+=solve(i-up,j-left,grid,dp);
        }
        else res+=solve(i,j-1,grid,dp);
        i=ni;
        j=nj;
    }
    return dp[i][j]=res%mod;
}
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long int>>dp(n,vector<long long int>(m,-1));
        return solve(n-1,m-1,grid,dp);
    }
};