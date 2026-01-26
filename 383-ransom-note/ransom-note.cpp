class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size(), m = magazine.size();
        if (n > m) return false;
        vector<int> magMp(26, 0);
        for (auto ch : magazine) magMp[ch - 'a']++;
        for (auto ch : ransomNote) {
            magMp[ch - 'a']--;
            if (magMp[ch - 'a'] < 0) return false;
        }
        return true;
    }
};