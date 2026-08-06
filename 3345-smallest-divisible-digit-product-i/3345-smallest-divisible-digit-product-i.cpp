class Solution {
public:
int digpro(int n){
    int x=1;
    while(n){
        x=x*(n%10);
        n/=10;
    }
    return x;
}
    int smallestNumber(int n, int t) {
        while(true){
            if(digpro(n)%t==0)return n;
            n++;
        }
        return 0;
    }
};