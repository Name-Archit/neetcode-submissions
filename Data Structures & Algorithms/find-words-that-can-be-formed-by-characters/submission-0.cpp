class Solution {
public:
    vector<int> countHash(string str){
        vector<int> hash(26, 0);

        for(int i=0; i<str.size(); i++){
            hash[str[i] - 'a']++;
        }

        return hash;
    }

    int countCharacters(vector<string>& words, string chars) {
        vector<int> hash(26, 0);

        for(auto it: chars) hash[it - 'a']++;        
        int maxSum = 0;

        for(auto it: words){  
            int sum = 0;          
            string str = it;
            vector<int> newHash = countHash(str);

            for(int i=0; i<str.size(); i++){
                if(hash[str[i] - 'a'] < newHash[str[i] - 'a']){
                    sum = 0;
                    break;
                }
                else sum++;
            }

            maxSum += sum;
        }
        
        return maxSum;
    }
};