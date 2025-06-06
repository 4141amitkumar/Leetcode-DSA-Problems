class Solution {
public:
    int reverse(int n){
        int rev=0;
        while(n){
            rev*=10;
            rev+=n%10;
            n/=10;
        }
        return rev;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
            s.insert(reverse(nums[i]));
        }
        return s.size();
    }
};