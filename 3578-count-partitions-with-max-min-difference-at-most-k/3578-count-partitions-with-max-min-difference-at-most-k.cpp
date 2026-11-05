class Solution {
public:
long long int mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long int>pref(n+1,0),dp(n+1,0);
        dp[0]=1;
        pref[0]=1;
        deque<int>maxi,mini;
        int left=0;
        for(int right=0;right<n;right++){
            while(!maxi.empty()&&nums[maxi.back()]<nums[right])maxi.pop_back();
            maxi.push_back(right);
            while(!mini.empty()&&nums[mini.back()]>nums[right])mini.pop_back();
            mini.push_back(right);
            while(nums[maxi.front()]-nums[mini.front()]>k){
                if(maxi.front()==left)maxi.pop_front();
                if(mini.front()==left)mini.pop_front();
                left++;
            }
            if(left==0)dp[right+1]=pref[right];
            else dp[right+1]=(pref[right]-pref[left-1]+mod)%mod;
            pref[right+1]=(pref[right]+dp[right+1])%mod;
        }
        return dp[n];
    }
};