class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,n=nums.size();
        int ans=0;
        long long int pro=1;
        for(int i=0;i<n;i++){
            pro*=nums[i];
            while(l<=i&&pro>=k){
                pro/=nums[l];
                l++;
            }
            ans+=i-l+1;
        }
        return ans;
    }
};