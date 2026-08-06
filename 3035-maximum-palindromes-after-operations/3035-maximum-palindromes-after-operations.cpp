class Solution {
public:
static bool comp(string&a,string&b){
    return a.size()<b.size();
}
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int>freq(26,0);
        for(auto& it:words){
            for(char c:it)freq[c-'a']++;
        }
        int matchingp=0;
        for(int i=0;i<26;i++){
            matchingp+=freq[i]/2;
        }
        sort(words.begin(),words.end(),comp);
        int cnt=0;
        for(auto& it:words){
            int n=it.size();
            int reqp=n/2;
            if(reqp<=matchingp){
                cnt++;
                matchingp-=reqp;
            }
        }
        return cnt;
    }
};