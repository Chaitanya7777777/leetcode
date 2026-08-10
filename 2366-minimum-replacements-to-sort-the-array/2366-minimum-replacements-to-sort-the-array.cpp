class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        int l=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>l){
                int ope=nums[i]/l;
                if(nums[i]%l)ope++;
                l=nums[i]/ope;
                ans+=ope-1;
            }
            else l=nums[i];
        }
        return ans;
    }
};