class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlen=1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            int len=1;
            if(nums[i]<nums[i+1]){
                for(int j=i+1;j<n;j++){
                    if(nums[j]>nums[j-1])len++;
                    else break;
                }
            }
            else{
                for(int j=i+1;j<n;j++){
                    if(nums[j]<nums[j-1])len++;
                    else break;
                }
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};