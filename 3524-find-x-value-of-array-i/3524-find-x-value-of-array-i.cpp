class Solution {
public:
long long solve(int i,int prevpro,int req,int k,vector<int>& nums,vector<vector<long long>>&dp){
    if(i==nums.size())return 0;
    if(dp[i][prevpro]!=-1)return dp[i][prevpro];
    long long skip=0,take=0;
    if(prevpro==k)skip=solve(i+1,prevpro,req,k,nums,dp);
    long long curpro;
    if(prevpro==k)curpro=nums[i];
    else curpro=(nums[i]*prevpro)%k;
    take+=(curpro==req);
    take+=solve(i+1,curpro,req,k,nums,dp);
    return dp[i][prevpro]=take+skip;
}
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>res(k,0);
        int n=nums.size();
        for(int i=0;i<n;i++)nums[i]=nums[i]%k;
        for(int i=0;i<k;i++){
            vector<vector<long long>>dp(n,vector<long long>(k+1,-1));
            res[i]+=solve(0,k,i,k,nums,dp);
        }
        return res;
    }
};