class Solution {
public:
    int addDigits(int num) {
        int x;
        int ans=0;
        while((num/10)!=0){
            x = num;
            while(x!=0){
                ans+=(x%10);
                x/=10;
            }
            num = ans;
            ans=0;
        }
        return num;
    }
};