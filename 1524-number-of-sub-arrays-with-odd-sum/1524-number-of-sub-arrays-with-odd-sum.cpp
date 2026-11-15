class Solution {
public:
long long int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int ev=1,od=0;
        long long int sum=0;
        long long int ans=0;
        for(auto& it:arr){
            sum+=it;
            if(sum&1){
                ans=(ans+ev)%mod;
                od+=1;
            }
            else{
                ans=(ans+od)%mod;
                ev+=1;
            }
        }
        return ans;
    }
};