class Solution {
    //abc
    //bba
    //leet
    //code
public:
string getminstr(vector<int>&cnt){
    string res="";
    for(int i=0;i<26;i++){
        while(cnt[i]>0){
            res+='a'+i;
            cnt[i]--;
        }
    }
    return res;
}
    string lexGreaterPermutation(string s, string target) {
        vector<int>cnt(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']++;
            cnt[target[i]-'a']--;
        }
        for(int i=n-1;i>=0;i--){
            int b=target[i]-'a';
            cnt[b]++;
            if(*min_element(cnt.begin(),cnt.end())<0)continue;
            for(int j=b+1;j<26;j++){
                if(cnt[j]){
                    target[i]='a'+j;
                    cnt[j]--;
                    target.resize(i+1);
                    return target+getminstr(cnt);
                }
            }
        }
        return "";
    }
};