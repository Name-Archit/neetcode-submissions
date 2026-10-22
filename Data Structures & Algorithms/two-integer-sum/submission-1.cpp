class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
          int n = nums.size();
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0, right = n - 1;

        while (left < right) {
            long long sum = (long long)arr[left].first + arr[right].first;

            if (sum == target) {
                int a = arr[left].second;
                int b = arr[right].second;

                if(a > b) swap(a, b);
                return {a, b};
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};
