class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ans(n,0);
        stack<int>st;
        int prevt=0;
        for(auto& it:logs){
            int p1=it.find(':');
            int p2=it.find(':',p1+1);
            int id=stoi(it.substr(0,p1));
            string type=it.substr(p1+1,p2-p1-1);
            int ti=stoi(it.substr(p2+1));
            if(type=="start"){
                if(!st.empty())ans[st.top()]+=ti-prevt;
                st.push(id);
                prevt=ti;
            }
            else{
                ans[st.top()]+=ti-prevt+1;
                st.pop();
                prevt=ti+1;
            }
        }
        return ans;
    }
};