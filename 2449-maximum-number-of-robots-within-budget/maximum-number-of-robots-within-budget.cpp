class Solution {
public:
    bool check(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget, int mid){
        if(mid==0) return true;
        int n = chargeTimes.size();
        priority_queue<pair<int,int>> pq;
        long long sum =0;
        for (int i=0; i<n;i++) {
            pq.push({chargeTimes[i], i});
            sum += runningCosts[i];
            if (i>=mid) {
                sum-=runningCosts[i-mid];
            }
            while (!pq.empty() && pq.top().second <= i-mid) {
                pq.pop();
            }
            if (i>=mid-1) {
                long long maxCharge = pq.top().first;
                long long cost=maxCharge + 1LL *mid* sum;
                if (cost<=budget) return true;
            }
        }
        return false;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int lo=0, hi=chargeTimes.size();
        int ans;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(chargeTimes, runningCosts, budget, mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans;
    }
};