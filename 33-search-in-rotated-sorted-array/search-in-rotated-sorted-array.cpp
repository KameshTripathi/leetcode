class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        bool notRotated = nums[0] <= nums[n - 1];
        if (notRotated) {
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
            return -1;
        }
        low = 0, high = n - 1;
        bool targetInPart1 = target <= nums[n - 1] && target <= nums[0];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == nums[n - 1]) {
                if (nums[mid] == target) return mid;
                else return -1;
            }
            else if (nums[mid] > nums[n - 1]) {
                if (targetInPart1) low = mid + 1;
                else {
                    if (nums[mid] == target) return mid;
                    else if (nums[mid] < target) low = mid + 1;
                    else if (nums[mid] > target) high = mid - 1;
                }
            } else if (nums[mid] < nums[n - 1]) {
                if (targetInPart1) {
                    if (nums[mid] == target) return mid;
                    else if (nums[mid] < target) low = mid + 1;
                    else if (nums[mid] > target) high = mid - 1;
                } else high = mid - 1;
            }
        }
        return -1;
    }
};