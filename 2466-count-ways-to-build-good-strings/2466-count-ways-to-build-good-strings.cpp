class Solution {
public:
long long int mod=1e9+7;
long long int solve(int n,int zero,int one,vector<long long int>&dp){
    if(n==0)return 1;
    if(dp[n]!=-1)return dp[n];
    long long int way=0;
    if(n-zero>=0)way=(way+solve(n-zero,zero,one,dp))%mod;
    if(n-one>=0)way=(way+solve(n-one,zero,one,dp))%mod;
    return dp[n]=way;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long int>dp(high+1,-1);
        long long int ans=0;
        for(int i=low;i<=high;i++){
            ans=(ans+solve(i,zero,one,dp))%mod;
        }
        return ans;
    }
};