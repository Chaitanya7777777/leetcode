class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==')'||grid[n-1][m-1]=='('||(n+m-1)%2==1)return false;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(n+m-1,0)));
        dp[0][0][1]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it=q.front(); q.pop();
            int d=it.first,x=it.second.first,y=it.second.second;
            if(x==n-1&&y==m-1&&d==0)return true;
            if(x<n-1){
                int nd=d;
                if(grid[x+1][y]=='(')nd++;
                else nd--;
                if(nd>=0&&!dp[x+1][y][nd]){
                    q.push({nd,{x+1,y}});
                    dp[x+1][y][nd]=1;
                }
            }
            if(y<m-1){
                int nd=d;
                if(grid[x][y+1]=='(')nd++;
                else nd--;
                if(nd>=0&&!dp[x][y+1][nd]){
                    q.push({nd,{x,y+1}});
                    dp[x][y+1][nd]=1;
                }
            }
        }
        return false;
    }
};