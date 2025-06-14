class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++){
            arr[i]=(arr[i]%k+k)%k; //for tackling the -ve numbers in input
            mp[arr[i]]++;
        }
        if(mp.find(0)!=mp.end()){
            if(mp[0]%2!=0) return false;
            mp.erase(0);
        }
        for(auto x:mp){
            int ele = x.first;
            int rem = k-ele;
            if(mp.find(rem)==mp.end()) return false;
            if(mp[ele]!=mp[rem]) return false;
        }
        return true;
    }
};