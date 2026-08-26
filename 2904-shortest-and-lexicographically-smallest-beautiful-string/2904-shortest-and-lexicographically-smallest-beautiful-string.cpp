class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans="";
        int cnt=0,n=s.size();
        int l=0;
        for(int i=0;i<n;i++){
            cnt+=(s[i]-'0');
            while(cnt==k){
                int len=i-l+1;
                if(ans.size()==0||len<ans.size()){
                    ans=s.substr(l,len);
                }
                else if(len==ans.size()){
                    string res=s.substr(l,len);
                    if(res<ans)ans=res;
                }
                cnt-=(s[l]-'0');
                l++;
            }
        }
        return ans;
    }
};