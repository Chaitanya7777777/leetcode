class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ind=0,ind2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ind=i;
            }
            if(nums[i]==n-1)ind2=i;
        }
        bool inc=true,dec=true;
        for(int i=1;i<n;i++){
            int j=(ind+i-1)%n;
            if(nums[j]>nums[(j+1)%n]){
                inc=false;
                break;
            }
        }
        for(int i=1;i<n;i++){
            int j=(ind2+i-1)%n;
            if(nums[j]<nums[(j+1)%n]){
                dec=false;
                break;
            }
        }
        if(inc==false&&dec==false)return -1;
        if(inc)return min(ind,2+n-ind2-1);
        return 1+min(ind2,n-ind-1);
    }
};