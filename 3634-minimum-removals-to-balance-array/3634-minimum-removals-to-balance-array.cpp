class Solution {
public:
int solve(vector<int>&nums,long long int k,int l,int r){
    long long int x=nums[l];
    int res=l;
    while(l<=r){
        int m=l+(r-l)/2;
        if(nums[m]<=k*x){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int id=solve(nums,k,i,n-1);
            ans=min(ans,i+(n-id-1));
        }
        return ans;
    }
};