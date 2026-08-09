class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int z=0,t=0;
        for(char c:s){
            if(c=='0')z++;
            else if(z>0)t=max(t+1,z);
        }
        return t;
    }
};