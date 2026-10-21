class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>cnt(k,0);
        cnt[0]=1;
        int psum=0;
        for(int x:nums){
            psum+=x;
            cnt[((psum%k)+k)%k]++;
        }
        int ans=0;
        for(int x:cnt){
            ans+=x*(x-1)/2;
        }
        return ans;
    }
};