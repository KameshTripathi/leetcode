class Solution {
public:
    bool check(vector<int>& weights, int days, int guess) {
        int n = weights.size();
        int x = guess, count = 0;
        for (int i = 0; i < n; ) {
            if (x < weights[i]) {
                x = guess;
                count++;
                continue;
            }
            x -= weights[i];
            i++;
        }
        return ++count <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 0, high = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            high += weights[i];
            if (low < weights[i]) low = weights[i];
        }
        cout << low << " " << high << endl;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(weights, days, mid)) {
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        return ans;
    }
};