class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == n - 1) return mid;
            else if (nums[mid] < nums[mid + 1]) low = mid + 1;
            else if (nums[mid] > nums[mid + 1]) {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};