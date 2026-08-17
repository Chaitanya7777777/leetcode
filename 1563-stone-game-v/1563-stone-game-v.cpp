class Solution {
public:
long long int solve(int l,int r,vector<int>&v,vector<vector<long long int>>&dp){
    if(l==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    long long int sum=accumulate(v.begin()+l,v.begin()+r+1,0LL);
    long long int sl=0;
    for(int i=l;i<r;i++){
        sl+=v[i];
        long long int sr=sum-sl;
        if(sl<sr){
            dp[l][r]=max(dp[l][r],solve(l,i,v,dp)+sl);
        }
        else if(sl>sr){
            dp[l][r]=max(dp[l][r],solve(i+1,r,v,dp)+sr);
        }
        else dp[l][r]=max(dp[l][r],max(solve(l,i,v,dp),solve(i+1,r,v,dp))+sl);
    }
    return dp[l][r];
}
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<vector<long long int>>dp(n,vector<long long int>(n,-1));
        return solve(0,n-1,stoneValue,dp);
    }
};