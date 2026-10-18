class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string>st(words.begin(),words.end());
        for(auto& it:words){
            for(int i=1;i<it.size();i++){
                st.erase(it.substr(i));
            }
        }
        int ans=0;
        for(auto& it:st)ans+=it.size()+1;
        return ans;
    }
};