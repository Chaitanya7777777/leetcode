class Solution {
public:
int solve(int i,int n,vector<int>&pre,vector<int>&dp){
    if(i==n-1)return pre[i];
    if(dp[i]!=-1)return dp[i];
    int nxt=solve(i+1,n,pre,dp);
    return dp[i]=max(nxt,pre[i]-nxt);
}
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>dp(n,-1);
        vector<int>pre(n);
        pre[0]=stones[0];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+stones[i];
        return solve(1,n,pre,dp);
    }
};