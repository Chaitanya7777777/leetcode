class Solution {
public:
    int minOperations(int n) {
        vector<int>o(32,0);
        int i=0;
        for(int i=0;i<32;i++){
            if(n&1)o[i]=1;
            n/=2;
        }
        int ans=0,cnt=0;
        for(int i=0;i<32;i++){
            if(o[i]==1)cnt++;
            else{
                if(cnt==1){
                    ans++;
                    cnt=0;
                }
                else if(cnt>1){
                    ans++;
                    cnt=1;
                }
            }
        }
        return ans;
    }
};