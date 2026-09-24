class Solution {
public:
int digsum(int x){
    int sum=0;
    while(x){
        sum+=x%10;
        x/=10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i==digsum(nums[i]))return i;
        }
        return -1;
    }
};