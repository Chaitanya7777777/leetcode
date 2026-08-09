class Solution {
public:
int solve(int ind,int mx,vector<int>&suff,vector<vector<int>>&dp){
    if(ind+2*mx>=suff.size())return suff[ind];
    if(dp[ind][mx]!=-1)return dp[ind][mx];
    int res=INT_MAX;
    for(int i=1;i<=2*mx;i++){
        res=min(res,solve(ind+i,max(mx,i),suff,dp));
    }
    return dp[ind][mx]=suff[ind]-res;
}
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        vector<int>suff(n);
        suff[n-1]=piles[n-1];
        for(int i=n-2;i>=0;i--)suff[i]=suff[i+1]+piles[i];
        return solve(0,1,suff,dp);
    }
};