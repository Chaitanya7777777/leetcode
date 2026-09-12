class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<bool>vis(1000,0);
        int cnt=0;
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]==0)continue;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                for(int k=0;k<n;k++){
                    if(k==j||k==i||digits[k]&1)continue;
                    int num=100*digits[i]+10*digits[j]+digits[k];
                    if(!vis[num]){
                        cnt++;
                        vis[num]=1;
                    }
                }
            }
        }
        return cnt;
    }
};