class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=nums[0],maxi=nums[0],mi=0,ma=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(mini>nums[i]){
                mini=nums[i];
                mi=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                ma=i;
            }
        }
        int diff=abs(ma-mi);
        int miniD=min(mi+1,n-mi);
        int maxiD=min(ma+1,n-ma);
        int ans=min(miniD,maxiD)+diff;
        ans=min(ans,miniD+maxiD);
        return ans;
    }
};