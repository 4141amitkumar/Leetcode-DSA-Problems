class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, count = 0, odd = 0;
        for (int r = 0; r < n; r++) {
            if (nums[r] % 2) odd++;
            while (odd > k) {
                if (nums[l] % 2) odd--;
                l++;
            }
            count += (r - l + 1); 
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
