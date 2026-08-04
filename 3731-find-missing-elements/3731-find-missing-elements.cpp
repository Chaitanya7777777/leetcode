class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums[0];
        vector<int>ans;
        for(int x:nums){
            while(l!=x){
                ans.push_back(l);
                l++;
            }
            l++;
        }
        return ans;
    }
};