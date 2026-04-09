class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        int s1_count[26] = {0}, window_count[26] = {0};
        for (char c : s1) s1_count[c - 'a']++;

        for (int j = 0; j < s2.size(); j++) {
            window_count[s2[j] - 'a']++;

            if (j >= s1.size()) {
                window_count[s2[j - s1.size()] - 'a']--;
            }

            bool match = true;
            for (int k = 0; k < 26; k++) {
                if (window_count[k] != s1_count[k]) {
                    match = false;
                    break;
                }
            }
            if (match) return true;
        }
        return false;
    }
};