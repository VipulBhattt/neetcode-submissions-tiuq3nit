class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, len = 0;
        unordered_map<char, int> st;

        for (int r = 0; r < s.length(); r++) {
            if (st.count(s[r]) && st[s[r]] >= l) {
                l = st[s[r]] + 1;
            }
            st[s[r]] = r;
            len = max(len, r - l + 1);
        }
        return len;
    }
};