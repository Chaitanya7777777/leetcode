class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool nonz=false;
        int x=0;
        for(int y:nums){
            if(y>0)nonz=true;
            x=x^y;
        }
        if(nonz){
            if(x)return nums.size();
            return nums.size()-1;
        }
        return 0;
    }
};