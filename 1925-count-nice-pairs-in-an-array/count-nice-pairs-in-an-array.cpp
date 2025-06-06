class Solution {
public:
    int reverse(int num){
        int ans=0;
        while(num!=0){
            ans*=10;
            ans+=(num%10);
            num/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> m;
        long long count=0;
        for(int i=0;i<nums.size();i++){
            int x = nums[i]-reverse(nums[i]);
            if(m.find(x)!=m.end()) count+=m[x];
            m[x]++;
        }
        return count%(1000000007);
    }
};