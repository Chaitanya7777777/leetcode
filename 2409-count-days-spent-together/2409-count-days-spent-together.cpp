class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>dom={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int>ps(1,0);
        for(int d:dom)ps.push_back(ps.back()+d);
        int aad=cdoy(arriveAlice,ps);
        int lad=cdoy(leaveAlice,ps);
        int abd=cdoy(arriveBob,ps);
        int lbd=cdoy(leaveBob,ps);
        return max(0,min(lad,lbd)-max(aad,abd)+1);
    }
    int cdoy(string& s,vector<int>&ps){
        int m=stoi(s.substr(0,2));
        int d=stoi(s.substr(3));
        return ps[m-1]+d;
    }
};