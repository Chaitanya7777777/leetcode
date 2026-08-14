class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l=0;
        unordered_map<char,int>m;
        int maxlen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            m[s[i]]++;
            while(m[s[i]]>2){
                m[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,i-l+1);
        }
        return maxlen;
    }
};