class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string temp="";
            int t=0;
            int sum=0;
            for(char c:s){
                sum+=(c-'0');
                t++;
                if(t==k){
                    t=0;
                    temp+=to_string(sum);
                    sum=0;
                }
            }
            if(t)temp+=to_string(sum);
            s=temp;
        }
        return s;
    }
};