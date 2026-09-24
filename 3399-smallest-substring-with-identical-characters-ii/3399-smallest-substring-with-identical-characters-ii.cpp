class Solution {
public:
bool check(string& s,int numOps,char ch){
    for(int i=0;i<s.size();i++){
        if(i&1){
            if(s[i]!=ch)numOps--;
        }
        else{
            if(s[i]!=ch)numOps--;
        }
        if(ch=='0')ch='1';
        else ch='0';
    }
    return numOps>=0;
}
bool isvalid(int mid,string& s,int numOps){
    int cnt=1;
    for(int i=1;i<s.size();i++){
        if(s[i]==s[i-1])cnt++;
        else{
            numOps-=cnt/(mid+1);
            cnt=1;
        }
    }
    numOps-=cnt/(mid+1);
    return numOps>=0;
}
    int minLength(string s, int numOps) {
        if(check(s,numOps,'1')||check(s,numOps,'0'))return 1;
        int l=2,r=s.size(),ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isvalid(mid,s,numOps)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};