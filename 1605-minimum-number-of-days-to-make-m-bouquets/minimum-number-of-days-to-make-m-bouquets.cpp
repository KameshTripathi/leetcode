class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k, int days) {
        int n = bloomDay.size();
        if (n < m * 1LL * k) return false;
        int flowers = k;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days) flowers--;
            else flowers = k;
            if (flowers == 0) {
                m--;
                flowers = k;
            }
            if (m == 0) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = 1, high = 1, ans = -1;
        for (int i = 0; i < n; i++) {
            if (high < bloomDay[i]) high = bloomDay[i];
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};