class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long int x=(nums[(n-1)/2]+nums[n/2])/2;
        long long int ans=0;
        for(auto& it:nums)ans+=abs(x-it);
        return ans;
    }
};