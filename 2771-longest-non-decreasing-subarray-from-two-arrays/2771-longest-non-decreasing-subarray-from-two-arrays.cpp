class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int dp1=1,dp2=1;
        int ans=1;
        for(int i=1;i<n;i++){
            int ndp1=1,ndp2=1;
            if(nums1[i]>=nums1[i-1])ndp1=max(ndp1,dp1+1);
            if(nums1[i]>=nums2[i-1])ndp1=max(ndp1,dp2+1);
            if(nums2[i]>=nums2[i-1])ndp2=max(ndp2,dp2+1);
            if(nums2[i]>=nums1[i-1])ndp2=max(ndp2,dp1+1);
            ans=max({ans,ndp1,ndp2});
            dp1=ndp1;
            dp2=ndp2;
        }
        return ans;
    }
};