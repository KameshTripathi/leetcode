class Solution {
public:
    bool check(vector<int>& candies, long long k, int mid) {
        int n = candies.size();
        long long count = 0;
        for (int i = 0; i < n; i++) {
            count += candies[i] / mid;
            if (count >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low = 1, high = 1, ans = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (candies[i] > high) high = candies[i];
            sum += candies[i];
        }
        if (sum < k) return 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(candies, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};