class Solution {
public:
    int minMoves(vector<int>& nums) {
        return nums.size()*(*max_element(nums.begin(),nums.end()))-accumulate(nums.begin(),nums.end(),0);
    }
};