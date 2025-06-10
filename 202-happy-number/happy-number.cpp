class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1 && s.find(n)==s.end()){
            s.insert(n);
            int x=0;
            while(n!=0){
                x+=((n%10)*(n%10));
                n/=10;
            }
            n=x;
        }
        if(n==1) return true;
        else return false;
    }
};