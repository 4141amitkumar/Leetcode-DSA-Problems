class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(int x:nums1){
            s.insert(x);
        }
        unordered_set<int> ans;
        for(int x:nums2){
            if(s.count(x)) ans.insert(x);
        }
        return vector<int>(ans.begin(),ans.end());
    }
};