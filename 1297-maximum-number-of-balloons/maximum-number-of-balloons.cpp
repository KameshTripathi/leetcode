// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         string s = "balloon";
//         vector<int> mp(26, 0);
//         for (auto ch : text) mp[ch - 'a']++;
//         int count = 0;
//         while (true) {
//             for (auto ch : s) {
//                 mp[ch - 'a']--;
//                 if (mp[ch - 'a'] < 0) return count;
//             }
//             count++;
//         }
//         return 0;
//     }
// };


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        unordered_map<char, int> textMp;
        unordered_map<char, int> sMp;
        for (auto ch : text) textMp[ch]++;
        for (auto ch : s) sMp[ch]++;
        int mini = INT_MAX;
        for (auto pair : sMp) {
            int key = pair.first;
            int need = pair.second;
            int have = textMp[key];
            int times = have / need;
            mini = min(mini, times);
        }
        return mini;
    }
};