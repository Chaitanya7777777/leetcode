class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        vector<bool>cov(n,false);
        for(int i=0;i<n;i++){
            if(cov[i])continue;
            for(int j=0;j<n;j++){
                if(i==j||cov[j]||words[i].size()<words[j].size())continue;
                int s=words[j].size(),t=words[i].size();
                string temp=words[i].substr(t-s);
                if(temp==words[j])cov[j]=true;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(cov[i])continue;
            ans+=words[i].size()+1;
        }
        return ans;
    }
};