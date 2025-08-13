class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        double x = (log(n))/log(3);
        return abs(x-round(x))<1e-10;
    }
};