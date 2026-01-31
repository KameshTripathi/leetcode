class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int i = 1, j = 1, cnt = 1;
        while (j < n) {
            if (nums[j] == nums[j - 1]) {
                if (cnt < 2) {
                    nums[i] = nums[j];
                    i++;
                }
                j++;
                cnt++;
            } else {
                nums[i] = nums[j];
                i++;
                j++;
                cnt = 1;
            }
        }
        return i;
    }
};