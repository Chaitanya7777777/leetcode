class Solution {
public:
    int minSwaps(string s) {
        int ans=0;
        int cnt=0;
        for(char c:s){
            if(c==']')cnt--;
            else cnt++;
            if(cnt<0){
                ans++;
                cnt=1;
            }
        }
        return ans;
    }
};