class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d=0,maxd=0;
        for(char c:seq){
            if(c=='(')d++;
            else d--;
            maxd=max(maxd,d);
        }
        int d1=(maxd+1)/2,d2=maxd/2;
        int n=seq.size();
        vector<int>ans(n);
        d=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='(')d++;
            else d--;
            if(seq[i]=='('){
                if(d<=d1)ans[i]=0;
                else ans[i]=1;
            }
            else{
                if(d<d1)ans[i]=0;
                else ans[i]=1;
            }
        }
        return ans;
    }
};