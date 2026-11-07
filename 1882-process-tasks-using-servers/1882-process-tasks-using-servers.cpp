class Solution {
public:
priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>idle,busy;
void free(long long int t,vector<int>& servers){
    while(!busy.empty()&&busy.top().first<=t){
        auto& it=busy.top();
        idle.push({servers[it.second],it.second});
        busy.pop();
    }
}
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=tasks.size(),m=servers.size();
        for(int i=0;i<m;i++)idle.push({servers[i],i});
        vector<int>ans(n);
        long long int t=0;
        for(long long int i=0;i<n;i++){
            t=max(t,i);
            free(t,servers);
            if(idle.empty()){
                t=busy.top().first;
                free(t,servers);
            }
            auto it=idle.top(); idle.pop();
            ans[i]=it.second;
            busy.push({t+tasks[i],it.second});
        }
        return ans;
    }
};