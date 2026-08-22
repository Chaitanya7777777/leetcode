class Solution {
public:
string solve(int l,int r,string& t){
    string ans="";
    for(int i=l;i<=r;i++){
        if(t[i]>='0'&&t[i]<='9'){
            int num=0;
            while(i<=r&&t[i]>='0'&&t[i]<='9'){
                num=num*10+(t[i]-'0');
                i++;
            }
            int le=i,re=i+1;
            int cnt=1;
            while(re<=r&&cnt>0){
                if(t[re]==']')cnt--;
                else if(t[re]=='[')cnt++;
                re++;
            }
            re--;
            string res=solve(le+1,re-1,t);
            while(num--)ans+=res;
            i=re;
            continue;
        }
        ans+=t[i];
    }
    return ans;
}
    string decodeString(string s) {
        int n=s.size();
        return solve(0,n-1,s);
    }
};