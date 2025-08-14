class Solution {
public:
    bool check(vector<int>& time, int totalTrips, long long mid){
        long long count=0;
        for(int i=0;i<time.size();i++){
            count+=(mid/time[i]);
        }
        if(count>=totalTrips) return true;
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int minimum=time[0];
        long long ans;
        for(int i=0;i<time.size();i++){
            minimum = min(minimum, time[i]);
        }
        long long lo=1, hi=(long long)(minimum)*totalTrips;
        while(lo<=hi){
            long long mid = lo+(hi-lo)/2;
            if(check(time, totalTrips, mid)){
                hi=mid-1;
                ans=mid;
            }
            else lo=mid+1;
        }
        return ans;
    }
};