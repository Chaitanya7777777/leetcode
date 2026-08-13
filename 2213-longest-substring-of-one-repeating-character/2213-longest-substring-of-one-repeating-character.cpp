class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        set<pair<int,int>>segs;
        multiset<int>l;
        for(int i=0;i<n;){
            int j=i;
            while(j<n&&s[i]==s[j])j++;
            segs.insert({i,j-1});
            l.insert(j-i);
            i=j;
        }
        int k=queryCharacters.size();
        vector<int>ans(k);
        for(int i=0;i<k;i++){
            int pos=queryIndices[i];
            char ch=queryCharacters[i];
            if(s[pos]!=ch){
                auto it=segs.upper_bound({pos,INT_MAX});
                it--;
                int L=it->first,R=it->second;
                segs.erase({it});
                l.erase(l.find(R-L+1));
                if(L<=pos-1){
                    segs.insert({L,pos-1});
                    l.insert(pos-L);
                }
                if(pos+1<=R){
                    segs.insert({pos+1,R});
                    l.insert(R-pos);
                }
                int nl=pos,nr=pos;
                auto rit=segs.lower_bound({pos+1,0});
                if(rit!=segs.end()&&rit->first==pos+1&&s[pos+1]==ch){
                    l.erase(l.find(rit->second-rit->first+1));
                    nr=rit->second;
                    segs.erase(rit);
                }
                auto lit=segs.lower_bound({pos,0});
                if(lit!=segs.begin()){
                    lit--;
                    if(lit->second==pos-1&&s[pos-1]==ch){
                        l.erase(l.find(lit->second-lit->first+1));
                        nl=lit->first;
                        segs.erase(lit);
                    }
                }
                segs.insert({nl,nr});
                l.insert(nr-nl+1);
                s[pos]=ch;
            }
            ans[i]=*l.rbegin();
        }
        return ans;
    }
};