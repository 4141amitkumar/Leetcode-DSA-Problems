class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i=0;
        if(digits[n-1]<9) digits[n-1] +=1;
        else{
            while(n-1-i>=0 && digits[n-1-i]==9){
            digits[n-1-i]=0;
            i++;
            }
            if (n-1-i >= 0) {
                digits[n-1-i] += 1;
            } else {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};