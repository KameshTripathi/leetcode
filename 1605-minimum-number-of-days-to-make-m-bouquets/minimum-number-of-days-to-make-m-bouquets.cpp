class Solution {
public:
    bool solve(vector<int>& bloomDay, int m, int k, int days) {
        int n = bloomDay.size();
        int flowersReq = k;
        int bouquetsReq = m;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= days) flowersReq--;
            else flowersReq = k;
            if (flowersReq == 0) {
                bouquetsReq--;
                flowersReq = k;
            }
            if (bouquetsReq == 0) return true;
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
            if (solve(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};