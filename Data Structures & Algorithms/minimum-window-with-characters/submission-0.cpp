class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> hash(256, 0);

        for(int i=0; i<m; i++){            
            hash[t[i]]++;
        }

        int left = 0;
        int right = 0;

        int maxLen = 0;
        int count = 0;

        int start = 0;
        int end = 0;

        while(right < n){ 

            if(hash[s[right]] > 0) count++;                
            hash[s[right]]--;                                    

            while(count == m){

                int len = right - left + 1;

                if(maxLen == 0 || maxLen > len){
                    maxLen = len;
                    start = left;
                    end = right;
                }

                if(hash[s[left]] >= 0) count--;                
                hash[s[left]]++;                                   

                left++;                
            }

            right++;
        }
        
        return s.substr(start, maxLen);
    }
};
