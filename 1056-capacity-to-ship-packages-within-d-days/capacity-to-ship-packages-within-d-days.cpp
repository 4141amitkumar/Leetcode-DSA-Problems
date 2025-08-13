class Solution {
public:
    bool check(vector<int>& weights, int days, int mid){
        int count=1;
        int x=mid;
        for(int i=0;i<weights.size();i++){
            if(x<weights[i]){
                count++;
                x=mid;
            }
            x-=weights[i];
        }
        if(count<=days) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maximum=0;
        int sum=0;
        for(int i=0;i<weights.size();i++){
            maximum=max(maximum, weights[i]);
            sum+=weights[i];
        }
        int a=maximum;
        int lo=a, hi=sum, ans;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(weights, days, mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};