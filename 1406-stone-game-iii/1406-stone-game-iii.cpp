class Solution {
public:
int solve(int i,int n,vector<int>&c,vector<int>&dp){
    if(i>=n)return 0;
    if(i==n-1)return c[i];
    if(dp[i]!=-1)return dp[i];
    int diff=c[i]-solve(i+1,n,c,dp);
    if(i+1<n)diff=max(diff,c[i]+c[i+1]-solve(i+2,n,c,dp));
    if(i+2<n)diff=max(diff,c[i]+c[i+1]+c[i+2]-solve(i+3,n,c,dp));
    return dp[i]=diff;
}
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>dp(n,-1);
        int x=solve(0,n,stoneValue,dp);
        if(x>0)return "Alice";
        else if(x<0)return "Bob";
        return "Tie";
    }
};