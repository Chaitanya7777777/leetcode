class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 0;
        sort(nums.begin(),nums.end());
        long long int cnt=0;
        int i=1;
        while(i<n&&nums[0]==nums[i])i++;
        long long int prev=nums[0];
        while(i<n){
            long long int cur=nums[i]+cnt;
            cnt+=cur-prev;
            prev=cur;
            i++;
        }
        return cnt;
    }
};