class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++)arr[i]=abs(nums[i]);
        sort(arr.begin(),arr.end());
        long long ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n&&arr[j]<=2*arr[i])j++;
            ans+=j-i-1;
        }
        return ans;
    }
};