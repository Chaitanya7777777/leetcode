class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int l=0,ans=0;
        unordered_map<string,int>freq;
        unordered_map<char,int>cnt;
        int n=s.size();
        for(int i=0;i<n;i++){
            cnt[s[i]]++;
            if(i-l+1>minSize){
                cnt[s[l]]--;
                if(cnt[s[l]]==0)cnt.erase(s[l]);
                l++;
            }
            if(i-l+1==minSize&&cnt.size()<=maxLetters){
                string t=s.substr(l,i-l+1);
                freq[t]++;
                ans=max(ans,freq[t]);
            }
        }
        return ans;
    }
};