class Solution {
public:
vector<int>dr={0,1,0,-1};
vector<int>dc={1,0,-1,0};
bool dfs(int r,int c,int row,int col,vector<vector<bool>>&vis){
    if(r==row-1)return true;
    vis[r][c]=true;
    for(int i=0;i<4;i++){
        int nr=r+dr[i],nc=c+dc[i];
        if(nr<0||nr==row||nc<0||nc==col||vis[nr][nc])continue;
        if(dfs(nr,nc,row,col,vis))return true;
    }
    return false;
}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int n=cells.size();
        int l=1,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>>vis(row,vector<bool>(col,false));
            for(int i=0;i<mid;i++){
                vis[cells[i][0]-1][cells[i][1]-1]=true;
            }
            bool possi=false;
            for(int i=0;i<col;i++){
                if(!vis[0][i]){
                    if(dfs(0,i,row,col,vis)){
                        possi=true;
                        break;
                    }
                }
            }
            if(possi){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};