class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int n=nums.size();
        int ans=INT_MAX;
        int l=0,r=n-1;
        while(l<n&&sum<x){
            sum+=nums[l];
            l++;
        }
        if(sum<x)return -1;
        if(sum==x)ans=l;
        l--;
        while(l<r&&l>=0){
            sum-=nums[l];
            l--;
            while(r>l&&sum<x){
                sum+=nums[r];
                r--;
            }
            if(sum==x)ans=min(ans,l+(n-r));
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};