class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int cy0=0,cy1=0,cy2=0;
        int c0=0,c1=0,c2=0;
        int n=grid.size();
        int n0=n/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<n0&&(j==i||j==n-i-1)){
                    if(grid[i][j]==0)cy0++;
                    else if(grid[i][j]==1)cy1++;
                    else cy2++;
                }
                else if(i>=n0&&j==n0){
                    if(grid[i][j]==0)cy0++;
                    else if(grid[i][j]==1)cy1++;
                    else cy2++;
                }
                else{
                    if(grid[i][j]==0)c0++;
                    else if(grid[i][j]==1)c1++;
                    else c2++;
                }
            }
        }
        int y=cy0+cy1+cy2;
        int ny=c0+c1+c2;
        int ans1=(y-cy0)+min(ny-c1,ny-c2);
        int ans2=(y-cy1)+min(ny-c0,ny-c2);
        int ans3=(y-cy2)+min(ny-c0,ny-c1);
        return min(ans1,min(ans2,ans3));
    }
};