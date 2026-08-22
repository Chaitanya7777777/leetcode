class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,pro=1;
        int n0=n;
        while(n0){
            int x=n0%10;
            n0/=10;
            sum+=x;
            pro*=x;
        }
        sum+=pro;
        return n%sum==0;
    }
};