class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> strings;

        for(string s:  strs){
            string key = s;
            sort(key.begin(), key.end());

            strings[key].push_back(s);
        }
        vector<vector<string>> result;

        for(auto& pair: strings){
            result.push_back(pair.second);
        }

        return result;
    }
};
