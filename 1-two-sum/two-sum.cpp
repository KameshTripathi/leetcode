// brute
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int> ans(2, -1);
//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target) {
//                     ans = {i, j};
//                     return ans;
//                 }
//             }
//         }
//         return ans;
//     }
// };


// better
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mp.find(complement) != mp.end()) {
                ans = {i, mp[complement]};
                return ans;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};