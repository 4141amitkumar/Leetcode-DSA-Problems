class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int x:nums){
            m[x]++;
        }
        sort(nums.begin(),nums.end(),[&](int a, int b){
            if(m[a]!=m[b]) return m[a]<m[b];  // // Lower frequency comes first
            return a>b; // If same frequency, larger number comes first
        });
        return nums;
    }
};