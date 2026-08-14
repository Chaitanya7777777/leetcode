class Solution {
public:
int solve(int id,int k,vector<int>&p,vector<vector<int>>&dp){
    if(id==p.size()||k==0)return 0;
    if(dp[id][k]!=-1)return dp[id][k];
    int pro=0;
    if(k&1){
        pro=max(p[id]+solve(id+1,k-1,p,dp),solve(id+1,k,p,dp));
    }
    else pro=max(-p[id]+solve(id+1,k-1,p,dp),solve(id+1,k,p,dp));
    return dp[id][k]=pro;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
        return solve(0,2*k,prices,dp);
    }
};