class Solution {
public:
bool possi(string& s,int numOps,char ch){
    for(int i=0;i<s.size();i++){
        if(i&1){
            if(s[i]!=ch)numOps--;
        }
        else{
            if(s[i]!=ch)numOps--;
        }
        if(ch=='1')ch='0';
        else ch='1';
    }
    return numOps>=0;
}
bool isvalid(int mid,string& s,int numOps){
    if(mid==1){
        return possi(s,numOps,'1')||possi(s,numOps,'0');
    }
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
        int l=1,r=s.size();
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(isvalid(mid,s,numOps)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};