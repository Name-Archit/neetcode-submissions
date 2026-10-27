class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        
        int left = 0;
        int right = 0;
        int maxFreq = -1;
        int maxLen = -1;

        vector<int> hash(26, 0);

        while(right < n){
            hash[s[right] - 'A']++;
            maxFreq = max(maxFreq, hash[s[right] - 'A']);

            int currLen = right - left + 1;

            if(currLen - maxFreq <= k) maxLen = max(maxLen, currLen);
            else{
                hash[s[left] - 'A']--;
                left++;

                for(int i=0; i<26; i++) maxFreq = max(maxFreq, hash[i]);                
            }

            right++;
        }

        return maxLen;
    }
};
