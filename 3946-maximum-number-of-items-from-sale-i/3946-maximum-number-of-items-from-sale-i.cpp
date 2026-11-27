class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int>cnt(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&items[j][0]%items[i][0]==0)cnt[i]++;
            }
        }
        vector<int>dp(budget+1,-1e9);
        dp[0]=0;
        for(int i=0;i<n;i++){
            int pri=items[i][1],gain=1+cnt[i];
            for(int b=budget;b>=pri;b--){
                dp[b]=max(dp[b],dp[b-pri]+gain);
            }
        }
        int cheap=INT_MAX;
        for(int i=0;i<n;i++)cheap=min(cheap,items[i][1]);
        int ans=0;
        for(int b=0;b<=budget;b++){
            int rem=budget-b;
            ans=max(ans,dp[b]+(rem/cheap));
        }
        return ans;
    }
};