
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        priority_queue<pair<int, int>> pq;

        for (auto& entry : freq) {
            pq.push({entry.second, entry.first});
        }

        vector<int> result;

        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
