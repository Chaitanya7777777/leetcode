class Solution {
public:
int solve(int mask,int n,int pos,vector<vector<int>>&dp){
    if(mask==(1<<n)-1)return 1;
    if(dp[mask][pos]!=-1)return dp[mask][pos];
    int ans=0;
    for(int i=1;i<=n;i++){
        int temp=(1<<(i-1));
        if(!(temp&mask)&&(pos%i==0||i%pos==0)){
            ans+=solve(temp|mask,n,pos+1,dp);
        }
    }
    return dp[mask][pos]=ans;
}
    int countArrangement(int n) {
        vector<vector<int>>dp(1<<n,vector<int>(n+1,-1));
        return solve(0,n,1,dp);
    }
};