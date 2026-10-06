class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0,cnt=0;
        for(char c:s){
            if(c=='(')cnt++;
            else{
                if(cnt==0)ans++;
                else cnt--;
            }
        }
        return ans+cnt;
    }
};