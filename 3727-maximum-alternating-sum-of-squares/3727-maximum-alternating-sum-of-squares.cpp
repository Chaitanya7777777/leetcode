class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)nums[i]=(nums[i]*nums[i]);
        sort(nums.begin(),nums.end());
        int l=0,r=n-1;
        long long int ans=0;
        while(l<r){
            ans+=nums[r]-nums[l];
            l++;
            r--;
        }
        if(l==r)ans+=nums[l];
        return ans;
    }
};