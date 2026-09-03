class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=nums1[0];
        bool odd=false;
        for(int x:nums1){
            if(x<mini)mini=x;
            if(x&1)odd=true;
        }
        if(mini&1)return true;
        return !odd;
    }
};