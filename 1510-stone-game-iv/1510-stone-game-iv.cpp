class Solution {
public:
bool solve(int n,vector<int>&dp){
    if(n==0)return false;
    if(dp[n]!=0)return dp[n]==1;
    bool win=false;
    for(int i=1;i*i<=n;i++){
        if(!solve(n-i*i,dp)){
            win=true;
            break;
        }
    }
    if(win)dp[n]=1;
    else dp[n]=2;
    return win;
}
    bool winnerSquareGame(int n) {
        vector<int>dp(n+1,0);
        return solve(n,dp);
    }
};