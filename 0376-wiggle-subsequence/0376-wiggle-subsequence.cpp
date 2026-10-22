class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]){
                nums.erase(nums.begin()+i);
                i--;
                n--;
            }
        }
        if(n==1)return 1;
        for(int i=1;i<n-1;i++){
            int o=nums[i]-nums[i-1];
            int t=nums[i+1]-nums[i];
            if((o>0&&t<0)||(o<0&&t>0))cnt++;
        }
        if(nums[n-1]!=nums[n-2])cnt++;
        return cnt+1;
    }
};