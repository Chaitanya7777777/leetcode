class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long int ans=0;
        long long int pre=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pre+=nums[i];
            ans=max(ans,(pre+i)/(i+1));
        }
        return ans;
    }
};