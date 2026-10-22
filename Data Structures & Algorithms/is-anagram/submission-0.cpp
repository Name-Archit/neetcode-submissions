class Solution {
public:
    bool isAnagram(string s, string t) {
          vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);

        if(s.size() != t.size()) return 0;

        for(int i=0; i<s.size(); i++){
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(freqS[i] != freqT[i]) return 0;
        }

        return 1;
    }
};
