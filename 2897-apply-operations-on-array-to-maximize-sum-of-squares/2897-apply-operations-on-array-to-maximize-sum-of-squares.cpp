class Solution {
public:
long long int mod=1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>bi(32,0);
        for(int x:nums){
            for(int i=0;i<32;i++){
                if(x&(1<<i))bi[i]++;
            }
        }
        long long int ans=0;
        while(k--){
            long long int x=0;
            for(int i=0;i<32;i++){
                if(bi[i]>0){
                    bi[i]--;
                    x+=(1<<i);
                }
            }
            ans+=x*x;
            ans=ans%mod;
        }
        return ans;
    }
};