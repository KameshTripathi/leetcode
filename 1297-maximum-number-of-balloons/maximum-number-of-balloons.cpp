class Solution {
public:
    int maxNumberOfBalloons(string text) {
        string s = "balloon";
        vector<int> mp(26, 0);
        for (auto ch : text) mp[ch - 'a']++;
        int count = 0;
        while (true) {
            for (auto ch : s) {
                mp[ch - 'a']--;
                if (mp[ch - 'a'] < 0) return count;
            }
            count++;
        }
        return 0;
    }
};