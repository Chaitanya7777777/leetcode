class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(nums.size()==1)return nums[0];
        if(k==1){
            unordered_map<int,int>m;
            for(int x:nums)m[x]++;
            int ans=-1;
            for(auto it:m){
                if(it.second==1)ans=max(ans,it.first);
            }
            return ans;
        }
        int l=nums[0],r=nums.back();
        int n=nums.size();
        if(k==n)return *max_element(nums.begin(),nums.end());
        if(l==r)return -1;
        for(int i=1;i<n-1;i++){
            if(nums[i]==l)l=-1;
            else if(nums[i]==r)r=-1;
        }
        return max(l,r);
    }
};