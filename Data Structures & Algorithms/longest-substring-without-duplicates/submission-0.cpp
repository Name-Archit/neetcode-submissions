
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> unmap;

        int left = 0;
        int right = 0;
        int maxLen = 0;

        while (right < n) {
            if (unmap.find(s[right]) != unmap.end()) {
                int pos = unmap[s[right]];
                left = max(left, pos + 1);
            }

            unmap[s[right]] = right;

            int len = right - left + 1;
            maxLen = max(maxLen, len);

            right++;
        }

        return maxLen;
    }
};
