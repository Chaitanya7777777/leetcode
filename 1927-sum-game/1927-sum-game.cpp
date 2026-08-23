class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int sumf=0,sums=0,cntf=0,cnts=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?')cntf++;
            else sumf+=(num[i]-'0');
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?')cnts++;
            else sums+=(num[i]-'0');
        }
        if((cntf+cnts)%2)return true;
        if(cntf==cnts){
            return sumf!=sums;
        }
        if(cntf>cnts){
            cntf-=cnts;
            cntf/=2;
            int diff=sums-sumf;
            return 9*cntf!=diff;
        }
        else{
            cnts-=cntf;
            cnts/=2;
            int diff=sumf-sums;
            return 9*cnts!=diff;
        }
        return true;
    }
};