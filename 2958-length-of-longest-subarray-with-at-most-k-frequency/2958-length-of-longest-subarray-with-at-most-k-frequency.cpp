class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans=0,l=-1;
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            while(m[nums[i]]>k){
                l++;
                m[nums[l]]--;
            }
            ans=max(ans,i-l);
        }
        return ans;
    }
};