class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>st;
        for(auto& it:reservedSeats){
            int r=it[0],s=it[1];
            if(s>=2&&s<=5)st[r].insert(0);
            if(s>=4&&s<=7)st[r].insert(1);
            if(s>=6&&s<=9)st[r].insert(2);
        }
        int ans=2*n;
        for(auto& it:st){
            if(it.second.size()==3)ans-=2;
            else ans-=1;
        }
        return ans;
    }
};