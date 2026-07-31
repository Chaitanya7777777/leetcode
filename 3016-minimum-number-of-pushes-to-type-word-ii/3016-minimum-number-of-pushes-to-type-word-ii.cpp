class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char& c:word)freq[c-'a']++;
        priority_queue<int>pq;
        for(auto& x:freq){
            if(x>0)pq.push(x);
        }
        int dis=0;
        int ans=0;
        while(!pq.empty()){
            int mul=1+(dis/8);
            ans+=mul*pq.top();
            pq.pop();
            dis++;
        }
        return ans;
    }
};