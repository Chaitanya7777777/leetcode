class Solution {
public:
int solve(int id,int n,int d,vector<int>&j,vector<vector<int>>&dp){
    if(d==1){
        int maxi=0;
        for(int i=id;i<n;i++)maxi=max(maxi,j[i]);
        return maxi;
    }
    if(dp[id][d]!=-1)return dp[id][d];
    int maxi=0,res=INT_MAX;
    for(int i=id;i<=n-d;i++){
        maxi=max(maxi,j[i]);
        res=min(res,maxi+solve(i+1,n,d-1,j,dp));
    }
    return dp[id][d]=res;
}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        if(d>n)return -1;
        vector<vector<int>>dp(n,vector<int>(d+1,-1));
        return solve(0,n,d,jobDifficulty,dp);
    }
};