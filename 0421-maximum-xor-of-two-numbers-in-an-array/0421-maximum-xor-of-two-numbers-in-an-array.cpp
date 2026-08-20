class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0,mask=0;
        for(int b=31;b>=0;b--){
            mask=mask|(1<<b);
            unordered_set<int>st;
            for(int x:nums)st.insert(mask&x);
            int temp=ans|(1<<b);
            for(int x:st){
                if(st.count(x^temp)){
                    ans=temp;
                    break;
                }
            }
        }
        return ans;
    }
};