class Solution {
public:
    bool check(vector<int>& citations, int h) {
        int n = citations.size();
        return citations[n - h] >= h;
    }
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(citations, mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};