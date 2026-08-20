class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>a1,a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);
        for(int i=2;i<nums.size();i++){
            if(a1.back()>a2.back())a1.push_back(nums[i]);
            else a2.push_back(nums[i]);
        }
        vector<int>res(nums.size());
        int i=0;
        for(int x:a1)res[i++]=x;
        for(int y:a2)res[i++]=y;
        return res;
    }
};