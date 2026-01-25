class Solution {
public:
    bool solve(vector<int>& piles, int h, int speed) {
        int n = piles.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (piles[i] % speed == 0) sum += piles[i] / speed;
            else sum += piles[i] / speed + 1;
        }
        return sum <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = 1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (high < piles[i]) {
                high = piles[i];
            }
        }
        for (int i = 1; i <= 30; i++) {
            cout << solve(piles, h, i) << endl;
        }
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (solve(piles, h, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};