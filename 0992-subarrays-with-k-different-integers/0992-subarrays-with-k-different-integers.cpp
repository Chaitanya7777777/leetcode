class Solution {
public:
    int cntsub(vector<int>& nums, int k){
        int l=0,r=0,ans=0;
        unordered_map<int,int>m;
        int dist=0;
        while(r<nums.size()){
            m[nums[r]]++;
            if(m[nums[r]]==1)dist++;
            while(dist>k){
                m[nums[l]]--;
                if(m[nums[l]]==0)dist--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return cntsub(nums,k)-cntsub(nums,k-1);
    }
};